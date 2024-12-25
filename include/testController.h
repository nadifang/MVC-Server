#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include "routerFramework.h"
#include "controllerFramework.h"

class testController : public Controller {
	DECLARE_FUN(0)
public:
	ModelAndView test(map<string, string> args);
};

#endif // TESTCONTROLLER_H
