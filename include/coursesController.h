#ifndef COURSECONTROLLER_H
#define COURSECONTROLLER_H

#include <routerFramework.h>
#include "controllerFramework.h"
#include "dataService.h"

class CoursesController : public Controller {
	DECLARE_FUN(0)
public:
	ModelAndView courses(map<string, string> args);
};

#endif // COURSECONTROLLER_H
