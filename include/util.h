#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
using namespace std;

string loadFile(const string &);

string loadImg(const string &);

int getPublic(string &path, string &buffer, string &type);

string getTime();

vector<string> split(string &s, char c);

#endif // UTIL_H
