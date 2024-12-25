#include "mainController.h"
#include "routerFramework.h"

IMPLEMENT_FUN(MainController, 0, getMainPage)

ModelAndView MainController::getMainPage(map<string, string> args) {
	ModelAndView m;
	m.pageName = "index.html";
	return m;
}
