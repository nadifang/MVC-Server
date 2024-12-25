#include "testController.h"
#include "globalConfig.h"

IMPLEMENT_FUN(testController, 0, test)

ModelAndView testController::test(map<string, string> args) {
	ModelAndView m;
	m.args     = args;
	m.pageName = "test.html";
	return m;
}
