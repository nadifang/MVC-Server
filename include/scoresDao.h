#ifndef SCORESDAO_H
#define SCORESDAO_H

#include "csvDao.h"

class ScoresDao : public CsvDao {
public:
	ScoresDao(const string &path)
	    : CsvDao{path} {}
	~ScoresDao() = default;
	map<string, string> getCourseIdAndScoreByStuId(const string &stuId);
	map<string, string> getStuIdAndScoreByCourseId(const string &courseId);
};

extern ScoresDao scoresDao;

#endif // SCORESDAO_H
