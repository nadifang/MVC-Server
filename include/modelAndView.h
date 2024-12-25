#ifndef MODELANDVIEW_H
#define MODELANDVIEW_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class ModelAndView {
public:
	string pageName;
	map<string, string> args;
	vector<map<string, string> > table;
};

#endif // MODELANDVIEW_H
