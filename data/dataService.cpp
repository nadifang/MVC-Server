#include "dataService.h"

#include <coursesDao.h>
#include <scoresDao.h>

map<string, string> getStudentInfoById(const string &id) {
	map<string, string> m;
	m["id"]   = id;
	m["name"] = studentsDao.getNameById(id);
	m["age"]  = studentsDao.getAgeById(id);
	m["sex"]  = studentsDao.getSexById(id);
	return m;
}

vector<map<string, string> > getCourseInfoByStuId(const string &stuId) {
	vector<map<string, string> > res;
	map<string, string> courseAndScore = scoresDao.getCourseIdAndScoreByStuId(stuId);
	for (auto it = courseAndScore.begin(); it != courseAndScore.end(); ++it) {
		map<string, string> m;
		m["course-name"] = coursesDao.getNameById(it->first);
		m["score"]       = it->second;
		m["time"]        = coursesDao.getTimeById(it->first);
		m["location"]    = coursesDao.getLocationById(it->first);
		m["teacher"]     = coursesDao.getTeacherById(it->first);
		res.push_back(m);
	}
	return res;
}

vector<map<string, string> > getAllStudents() {
	return studentsDao.getAll();
}

vector<map<string, string> > getAllCourses() {
	return coursesDao.getAll();
}

// -1 means no boundary, -2 means invalid
vector<map<string, string> > getStudentByAgeRange(int from, int to) {
	vector<map<string, string> > ori = studentsDao.getAll();
	vector<map<string, string> > res;
	if (from == -2 || to == -2)
		return res;
	if (from == -1)
		from = 0;
	if (to == -1)
		to = INT_MAX;
	for (auto it = ori.begin(); it != ori.end(); ++it) {
		int age = stoi(it->at("age"));
		if (age >= from && age <= to)
			res.push_back(*it);
	}
	return res;
}

map<string, string> getCourseInfoByName(const string &name) {
	map<string, string> m;
	m["id"]       = coursesDao.getIdByName(name);
	m["time"]     = coursesDao.getTimeByName(name);
	m["location"] = coursesDao.getLocationByName(name);
	m["teacher"]  = coursesDao.getTeacherByName(name);
	m["name"]     = name;
	return m;
}

vector<map<string, string> > getStuInfoByCourseName(const string &name) {
	string courseId = coursesDao.getIdByName(name);
	vector<map<string, string> > res;
	map<string, string> stuAndScore = scoresDao.getStuIdAndScoreByCourseId(courseId);
	for (auto it = stuAndScore.begin(); it != stuAndScore.end(); ++it) {
		map<string, string> m;
		m["stu-name"] = studentsDao.getNameById(it->first);
		m["score"]    = it->second;
		m["age"]      = studentsDao.getAgeById(it->first);
		m["stu-id"]   = it->first;
		m["sex"]      = studentsDao.getSexById(it->first);
		res.push_back(m);
	}
	return res;
}
