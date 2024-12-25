#include "util.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <globalConfig.h>

string loadFile(const string &path) {
	if (path.find(".png") != string::npos)
		return loadImg(path);
	// cout << "Opening File: " << path << endl;
	ifstream ifs(path);
	// if (ifs.is_open()) cout << "File Opened." << endl;
	string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
	return content;
}

string loadImg(const string &path) {
	char *buffer;
	FILE *fp = fopen(path.c_str(), "rb");
	if (fp == nullptr) {
		cout << "Open Image Failed." << endl;
		return "";
	}
	fseek(fp, 0, SEEK_END);
	string::size_type size = ftell(fp);
	rewind(fp);
	buffer        = new char[size];
	size_t result = fread(buffer, 1, size, fp);
	if (result != size) {
		cout << "Read Image Failed." << endl;
		return "";
	}
	fclose(fp);
	string res{buffer, size};
	delete[] buffer;
	return res;
}

int getPublic(string &path, string &buffer, string &type) {
	if (path.find(RESOURCE_PATH) != 1)
		return -1;
	if (path.find(".png") != string::npos)
		type = "png";
	if (path.find(".css") != string::npos)
		type = "css";
	string nPath = path.substr(1);
	buffer       = loadFile(nPath);
	return 0;
}

string getTime() {
	char t[100]{};
	time_t now;
	time(&now);
	strftime(t, 100, "%Y-%m-%d %X GMT+8", localtime(&now));
	return string(t);
}

vector<string> split(string &s, char c) {
	vector<string> res;
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2) {
		res.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length()) {
		res.push_back(s.substr(pos1));
	}
	return res;
}
