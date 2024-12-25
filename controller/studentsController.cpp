#include "studentsController.h"

IMPLEMENT_FUN(StudentsController, 0, students)

ModelAndView StudentsController::students(map<string, string> args) {
	ModelAndView m;
	if (args.find("agefrom") != args.end() ||
	    args.find("ageto") != args.end()) {
		int ageFrom, ageTo;
		double fromDouble{}, toDouble{};
		if (args.find("agefrom") != args.end() &&
		    !args["agefrom"].empty()) {
			try {
				ageFrom    = stoi(args["agefrom"]);
				fromDouble = stod(args["agefrom"]);
			} catch (...) {
				ageFrom                 = -2;
				args["warning-message"] = "Age must be a number.";
				args["agefrom"]         = "INVALID";
			}
			if (ageFrom != -2 && ageFrom != fromDouble) {
				args["warning-message"] = "Age must be an integer.";
				ageFrom                 = -2;
				args["agefrom"]         = "INVALID";
			} else if (args["agefrom"] != "INVALID") {
				args["agefrom"] = to_string(ageFrom);
			}
			if (ageFrom < 0 && args["agefrom"] != "INVALID") {
				args["warning-message"] = "Age must be a positive number.";
				ageFrom                 = -2; // student info won't show
				args["agefrom"]         = "INVALID";
			}
		} else {
			ageFrom         = -1; // -1 indicates no boundary
			args["agefrom"] = "ANY";
		}
		if (args.find("ageto") != args.end() &&
		    !args["ageto"].empty()) {
			try {
				ageTo    = stoi(args["ageto"]);
				toDouble = stod(args["ageto"]);
			} catch (...) {
				if (args.find("warning-message") == args.end())
					args["warning-message"] = "Age must be a number.";
				args["ageto"] = "INVALID";
				ageTo         = -2;
			}
			if (ageTo != -2 && ageTo != toDouble) {
				if (args.find("warning-message") == args.end())
					args["warning-message"] = "Age must be an integer.";
				args["ageto"] = "INVALID";
				ageTo         = -2;
			} else if (args["ageto"] != "INVALID") {
				args["ageto"] = to_string(ageTo);
			}
			if (ageTo < 0 && args["ageto"] != "INVALID") {
				if (args.find("warning-message") == args.end())
					args["warning-message"] = "Age must be a positive number.";
				ageTo         = -2; // student info won't show
				args["ageto"] = "INVALID";
			}
		} else {
			ageTo         = -1;
			args["ageto"] = "ANY";
		}
		if (ageFrom > 0 && ageTo > 0 && ageFrom > ageTo) {
			args["warning-message"] = "Age from should equal to or be less than age to.";
		}
		m.table = getStudentByAgeRange(ageFrom, ageTo);
		if (args["agefrom"] == "ANY" && args["ageto"] == "ANY") {
			args.erase("agefrom");
			args.erase("ageto");
		}
	} else {
		m.table = getAllStudents();
	}

	if (m.table.empty()) {
		if (args.find("warning-message") == args.end())
			args["warning-message"] = "No student found.";
	}

	m.args     = args;
	m.pageName = "students.html";
	return m;
}