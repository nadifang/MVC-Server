#include "router.h"
#include "routerFramework.h"
#include "controllerFramework.h"
#include "mainController.h"
#include "scoreController.h"
#include "testController.h"
#include "studentsController.h"
#include "coursesController.h"

void MyRouter::init() {
	REGISTER_FUN("GET", "/", MainController, 0);
	REGISTER_FUN("GET", "/scorebystudent/:stuId", ScoreController, 0);
	REGISTER_FUN("GET", "/scorebycourse/:courseName", ScoreController, 1);
	REGISTER_FUN("GET", "/test", testController, 0);
	REGISTER_FUN("GET", "/students", StudentsController, 0);
	REGISTER_FUN("GET", "/courses", CoursesController, 0);
}

MyRouter myRouter;