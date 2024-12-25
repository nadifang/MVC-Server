#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controllerFramework.h"
#include "routerFramework.h"

class MainController : public Controller {
	DECLARE_FUN(0)
public:
	ModelAndView getMainPage(map<string, string> args);
};

#endif // CONTROLLER_H
