#ifndef DATASERVICE_H
#define DATASERVICE_H

#include "studentsDao.h"

map<string, string> getStudentInfoById(const string &id);

vector<map<string, string> > getCourseInfoByStuId(const string &stuId);

vector<map<string, string> > getAllStudents();

vector<map<string, string> > getAllCourses();

vector<map<string, string> > getStudentByAgeRange(int from, int to);

map<string, string> getCourseInfoByName(const string &name);

vector<map<string, string> > getStuInfoByCourseName(const string &name);

#endif // DATASERVICE_H
