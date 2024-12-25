#include "coursesController.h"

IMPLEMENT_FUN(CoursesController, 0, courses)

ModelAndView CoursesController::courses(map<string, string> args) {
	ModelAndView m;
	m.pageName = "courses.html";
	m.args     = args;
	m.table    = getAllCourses();
	return m;
}