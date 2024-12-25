#ifndef STUDENTSCONTROLLER_H
#define STUDENTSCONTROLLER_H

#include <routerFramework.h>

#include "controllerFramework.h"
#include "dataService.h"

class StudentsController : public Controller {
	DECLARE_FUN(0)
public:
	ModelAndView students(map<string, string> args);
};

#endif // STUDENTSCONTROLLER_H
