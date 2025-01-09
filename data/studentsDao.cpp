#include "studentsDao.h"

string StudentsDao::getNameById(const string &id) {
	for (auto &student : data) {
		if (student["id"] == id) {
			return student["name"];
		}
	}
	throw runtime_error("500");
}

string StudentsDao::getAgeById(const string &id) {
	for (auto &student : data) {
		if (student["id"] == id) {
			return student["age"];
		}
	}
	throw runtime_error("500");
}
string StudentsDao::getSexById(const string &id) {
	for (auto &student : data) {
		if (student["id"] == id) {
			return student["sex"];
		}
	}
	throw runtime_error("500");
}

vector<map<string, string> > StudentsDao::getAll() {
	return data;
}

StudentsDao studentsDao{"students.csv"};