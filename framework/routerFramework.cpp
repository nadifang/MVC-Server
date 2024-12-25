#include "routerFramework.h"

#include "util.h"
#include <string>
#include <vector>
using namespace std;

Router *thisRouter;

Router::Router() {
	thisRouter = this;
}

ModelAndView Router::handle(map<string, string> &req) {
	string path = req["path"];
	if (path.length() > 1 &&
	    path[path.length() - 1] == '/')
		path = path.substr(0, path.length() - 1);
	string method = req["method"];
	for (auto it = table.begin(); it != table.end(); ++it) {
		map<string, string> args = req;
		if (it->method == method) {
			if (it->path != path) {
				if (it->path.rfind(':') != string::npos) {
					int pos = it->path.rfind(':');
					if (path.length() <= pos ||
					    it->path.substr(0, pos - 1) != path.substr(0, pos - 1))
						continue;
					string argName  = it->path.substr(pos + 1);
					string argValue = path.substr(pos);
					args[argName]   = argValue;
				} else if (path[it->path.length()] == '?') {
					string argS = path.substr(it->path.length() + 1);
					if (argS == "")
						throw "400";
					vector<string> argList = split(argS, '&');
					for (auto arg : argList) {
						vector<string> kv = split(arg, '=');
						if (kv.size() == 1)
							kv.push_back("");
						else if (kv.size() != 2)
							throw "400";
						args[kv[0]] = kv[1];
					}
				} else
					continue;
			}
			ModelAndView m;
			m = ((it->obj)->*(it->fun))(args);
			return m;
		}
	}
	throw "404";
}

void Router::addRouting(string method, string path, Controller *obj, CTRL_FUN fun) {
	RouterEle e;
	e.method = method;
	e.path   = path;
	e.obj    = obj;
	e.fun    = fun;
	table.push_back(e);
}
