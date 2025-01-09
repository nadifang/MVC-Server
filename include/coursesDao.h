#ifndef COURSESDAO_H
#define COURSESDAO_H

#include "csvDao.h"
#include <stdexcept>

class CoursesDao final : public CsvDao {
public:
	CoursesDao(const string &path)
	    : CsvDao{path} {}
	~CoursesDao() = default;
	string getNameById(const string &id);
	string getTimeById(const string &id);
	string getLocationById(const string &id);
	string getTeacherById(const string &id);

	string getIdByName(const string &name);
	string getTimeByName(const string &name);
	string getLocationByName(const string &name);
	string getTeacherByName(const string &name);

	vector<map<string, string> > getAll();
};

extern CoursesDao coursesDao;

#endif // COURSESDAO_H
