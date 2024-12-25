#ifndef ROUTERFRAMEWORK_H
#define ROUTERFRAMEWORK_H

#include <string>
#include <vector>
#include "controllerFramework.h"
#include "modelAndView.h"

#define DECLARE_FUN(n) \
public:                \
	ModelAndView f##n(map<string, string>) override;
#define IMPLEMENT_FUN(className, n, funName) \
	ModelAndView className::f##n(map<string, string> a) { return funName(a); }
#define REGISTER_FUN(method, path, className, n) addRouting(method, path, new className, (CTRL_FUN) & className::f##n);
using namespace std;

typedef ModelAndView (Controller::*CTRL_FUN)(map<string, string>);

struct RouterEle {
	string method;
	string path;
	Controller *obj;
	CTRL_FUN fun;
};

class Router {
public:
	Router();
	virtual ~Router()   = default;
	virtual void init() = 0;
	ModelAndView handle(map<string, string> &req);

private:
	vector<RouterEle> table;

protected:
	void addRouting(string method, string path, Controller *obj, CTRL_FUN fun);
};

#endif // ROUTERFRAMEWORK_H
