#include "coursesDao.h"

string CoursesDao::getNameById(const string &id) {
	for (auto &course : data) {
		if (course["id"] == id) {
			return course["name"];
		}
	}
	throw "500";
}

string CoursesDao::getTimeById(const string &id) {
	for (auto &course : data) {
		if (course["id"] == id) {
			return course["time"];
		}
	}
	throw "500";
}

string CoursesDao::getLocationById(const string &id) {
	for (auto &course : data) {
		if (course["id"] == id) {
			return course["location"];
		}
	}
	throw "500";
}

string CoursesDao::getTeacherById(const string &id) {
	for (auto &course : data) {
		if (course["id"] == id) {
			return course["teacher"];
		}
	}
	throw "500";
}

string CoursesDao::getIdByName(const string &name) {
	for (auto &course : data) {
		if (course["name"] == name) {
			return course["id"];
		}
	}
	throw "500";
}

string CoursesDao::getTimeByName(const string &name) {
	for (auto &course : data) {
		if (course["name"] == name) {
			return course["time"];
		}
	}
	throw "500";
}

string CoursesDao::getLocationByName(const string &name) {
	for (auto &course : data) {
		if (course["name"] == name) {
			return course["location"];
		}
	}
	throw "500";
}

string CoursesDao::getTeacherByName(const string &name) {
	for (auto &course : data) {
		if (course["name"] == name) {
			return course["teacher"];
		}
	}
	throw "500";
}

vector<map<string, string> > CoursesDao::getAll() {
	return data;
}

CoursesDao coursesDao{"courses.csv"};
