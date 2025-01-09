#include <iostream>
#include <windows.h>
#include <map>
#include "router.h"
#include "globalConfig.h"
#include "util.h"
#include "studentsDao.h"
#include "view.h"
#include "http.h"
#include <stdexcept>
using namespace std;

int main() {
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << "Initialization Failed." << endl;
		return -1;
	}
	cout << "Initialized." << endl;

	SOCKET sockServer = socket(AF_INET, SOCK_STREAM, 0);
	if (sockServer == INVALID_SOCKET) {
		cout << "Server Creation Failed." << endl;
		WSACleanup();
		return -1;
	}
	cout << "Server Socket Created." << endl;
	SOCKADDR_IN addr{};
	addr.sin_family           = AF_INET;
	addr.sin_port             = htons(PORT);
	addr.sin_addr.S_un.S_addr = inet_addr(IP);
	if (bind(sockServer, (sockaddr *)&addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR) {
		cout << "Binding Failed." << endl;
		closesocket(sockServer);
		WSACleanup();
		return -1;
	}
	cout << "Port Bound." << endl;

	myRouter.init();
	cout << "Router Initialized." << endl;

	if (listen(sockServer, 5) == SOCKET_ERROR) {
		cout << "Listening Failed." << endl;
		closesocket(sockServer);
		WSACleanup();
		return -1;
	}
	cout << "Listening." << endl;

	while (true) {
		cout << "Waiting For Client." << endl;
		SOCKADDR_IN clientAddr{};
		int nAddrLen      = sizeof(SOCKADDR_IN);
		SOCKET sockClient = accept(sockServer, (sockaddr *)&clientAddr, &nAddrLen);
		if (sockClient == INVALID_SOCKET) {
			cout << "Connection Failed." << endl;
			continue;
		}
		cout << "Connected." << endl;
		char szData[4096]{};
		int ret = 0;
		ret     = recv(sockClient, szData, sizeof(szData) - 1, 0);
		if (ret > 0) {
			szData[ret] = '\0';
			string dat(szData);
			map<string, string> an = analyse(dat);
			ModelAndView res;
			string type{}, buffer{};
			int code = 200;
			// search for resource
			if (an["method"] == "GET" &&
			    getPublic(an["path"], buffer, type) == 0) {
				string response = generateHeader(buffer, type, code) + buffer;
				ret             = send(sockClient, response.c_str(), response.length(), 0);
				if (ret == SOCKET_ERROR) {
					cout << "Sending Failed." << endl;
					closesocket(sockClient);
					continue;
					// break;
				}
				closesocket(sockClient);
				continue;
				// break;
			}
			// search for controller
			type = "html";
			try {
				res = myRouter.handle(an);
			} catch (runtime_error &e) {
				if (strcmp(e.what(), "404") == 0) {
					res.pageName = "error.html";
					map<string, string> a;
					a["errorMessage"] = "404 Not Found.";
					res.args          = a;
					code              = 404;
				} else if (strcmp(e.what(), "500") == 0) {
					res.pageName = "error.html";
					map<string, string> a;
					a["errorMessage"] = "500 Internal Server Error.";
					res.args          = a;
					code              = 500;
				} else if (strcmp(e.what(), "400") == 0) {
					res.pageName = "error.html";
					map<string, string> a;
					a["errorMessage"] = "400 Bad Request.";
					res.args          = a;
					code              = 400;
				}
			}
			string html;
			try {
				html = View::render(res);
			} catch (runtime_error &e) {
				if (strcmp(e.what(), "500") == 0) {
					ModelAndView error;
					error.pageName             = "error.html";
					error.args["errorMessage"] = "500 Internal Server Error.";
					html                       = View::render(error);
					code                       = 500;
				}
			}
			string response = generateHeader(html, type, code) + html;
			ret             = send(sockClient, response.c_str(), response.length(), 0);
			if (ret == SOCKET_ERROR) {
				cout << "Sending Failed." << endl;
				closesocket(sockClient);
				continue;
				// break;
			}
			closesocket(sockClient);
			continue;
			// break;
		} else if (ret == 0) {
			cout << "Connection Closed." << endl;
			closesocket(sockClient);
			continue;
			// break;
		} else {
			cout << "Receiving Failed." << endl;
			closesocket(sockClient);
			continue;
			// break;
		}
		// closesocket(sockClient);
		// cout << "Disconnected. Waiting For Next Client..." << endl;
	}

	closesocket(sockServer);
	WSACleanup();

	return 0;
}
