#ifndef CONTROLLERFRAMEWORK_H
#define CONTROLLERFRAMEWORK_H

#include "modelAndView.h"

class Controller {
public:
	virtual ~Controller() = default;
	virtual ModelAndView f0(map<string, string>) { return ModelAndView(); };
	virtual ModelAndView f1(map<string, string>) { return ModelAndView(); };
	virtual ModelAndView f2(map<string, string>) { return ModelAndView(); };
};

#endif // CONTROLLERFRAMEWORK_H
