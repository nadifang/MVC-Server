#ifndef SCORECONTROLLER_H
#define SCORECONTROLLER_H

#include "routerFramework.h"
#include "controllerFramework.h"
#include "modelAndView.h"

class ScoreController : public Controller {
	DECLARE_FUN(0)
	DECLARE_FUN(1)
public:
	ModelAndView scoreByStu(map<string, string> args);
	ModelAndView scoreByCourse(map<string, string> args);
};

#endif // SCORECONTROLLER_H
