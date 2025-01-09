#include "scoreController.h"
#include "dataService.h"

IMPLEMENT_FUN(ScoreController, 0, scoreByStu)
IMPLEMENT_FUN(ScoreController, 1, scoreByCourse)

ModelAndView ScoreController::scoreByStu(map<string, string> args) {
	string stuId = args["stuId"];
	ModelAndView m;
	m.pageName = "scores_by_stu.html";
	m.args     = getStudentInfoById(stuId);
	m.table    = getCourseInfoByStuId(stuId);
	return m;
}

ModelAndView ScoreController::scoreByCourse(map<string, string> args) {
	string courseName = args["courseName"];
	ModelAndView m;
	m.pageName = "scores_by_course.html";
	m.args     = getCourseInfoByName(courseName);
	m.table    = getStuInfoByCourseName(courseName);
	return m;
}
