#ifndef STUDENTSDAO_H
#define STUDENTSDAO_H

#include "csvDao.h"
#include <stdexcept>

class StudentsDao final : public CsvDao {
public:
	StudentsDao(const string &path)
	    : CsvDao(path) {}
	~StudentsDao() = default;
	string getNameById(const string &id);
	string getAgeById(const string &id);
	string getSexById(const string &id);
	vector<map<string, string> > getAll();
};

extern StudentsDao studentsDao;

#endif // STUDENTSDAO_H
