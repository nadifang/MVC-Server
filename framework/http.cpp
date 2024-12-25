#include "http.h"
#include "util.h"
#include <algorithm>

map<string, string> analyse(string &data) {
	int nowPos = 0;
	map<string, string> m;
	int sepPos    = data.find(' ', nowPos);
	m["method"]   = data.substr(nowPos, sepPos - nowPos);
	nowPos        = sepPos + 1;
	sepPos        = data.find(' ', nowPos);
	m["path"]     = data.substr(nowPos, sepPos - nowPos);
	nowPos        = sepPos + 1;
	sepPos        = data.find("\r\n", nowPos);
	m["protocol"] = data.substr(nowPos, sepPos - nowPos);
	nowPos        = sepPos + 2;
	while (data[nowPos] != '\r') {
		sepPos     = data.find("\r\n", nowPos);
		string key = data.substr(nowPos, data.find(':', nowPos) - nowPos);
		transform(key.begin(), key.end(), key.begin(), ::tolower);
		string value = data.substr(data.find(':', nowPos) + 2, sepPos - data.find(':', nowPos) - 2);
		m[key]       = value;
		nowPos       = sepPos + 2;
	}
	return m;
}

string generateHeader(string &data, string &type, int code) {
	if (code == 200 && type == "html")
		return generateHtmlOK(data);
	if (code == 500 && type == "html")
		return generateHtmlError(data);
	if (code == 404 && type == "html")
		return generateHtmlNotFound(data);
	if (code == 200 && type == "png")
		return generatePNGOK(data);
	if (code == 200 && type == "css")
		return generateCSSOK(data);
	return generateHtmlNotFound(data);
}

string generateHtmlOK(string &html) {
	string header  = "HTTP/1.1 200 OK\r\n";
	header        += "Server: C++ Job\r\n";
	header        += "Content-Type: text/html; charset=utf-8\r\n";
	header        += "Content-Length: " + to_string(html.length()) + "\r\n";
	header        += "Date: " + getTime() + "\r\n";
	header        += "\r\n";
	return header;
}

string generateHtmlError(string &html) {
	string header  = "HTTP/1.1 500 Internal Server Error\r\n";
	header        += "Server: C++ Job\r\n";
	header        += "Content-Type: text/html; charset=utf-8\r\n";
	header        += "Content-Length: " + to_string(html.length()) + "\r\n";
	header        += "Date: " + getTime() + "\r\n";
	header        += "\r\n";
	return header;
}

string generateHtmlNotFound(string &html) {
	string header  = "HTTP/1.1 404 Not Found\r\n";
	header        += "Server: C++ Job\r\n";
	header        += "Content-Type: text/html; charset=utf-8\r\n";
	header        += "Content-Length: " + to_string(html.length()) + "\r\n";
	header        += "Date: " + getTime() + "\r\n";
	header        += "\r\n";
	return header;
}

string generatePNGOK(string &png) {
	string header  = "HTTP/1.1 200 OK\r\n";
	header        += "Server: C++ Job\r\n";
	header        += "Content-Type: image/png\r\n";
	header        += "Content-Length: " + to_string(png.length()) + "\r\n";
	header        += "Date: " + getTime() + "\r\n";
	header        += "\r\n";
	return header;
}

string generateCSSOK(string &css) {
	string header  = "HTTP/1.1 200 OK\r\n";
	header        += "Server: C++ Job\r\n";
	header        += "Content-Type: text/css; charset=utf-8\r\n";
	header        += "Content-Length: " + to_string(css.length()) + "\r\n";
	header        += "Date: " + getTime() + "\r\n";
	header        += "\r\n";
	return header;
}
