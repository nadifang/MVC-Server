#ifndef HTTP_H
#define HTTP_H

#include <string>
#include <map>
using namespace std;

map<string, string> analyse(string &data);

string generateHeader(string &data, string &type, int code);
string generateHtmlOK(string &html);
string generateHtmlError(string &html);
string generateHtmlNotFound(string &html);

string generatePNGOK(string &png);
string generateCSSOK(string &css);

#endif // HTTP_H
