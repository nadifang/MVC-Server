#ifndef CSVDAO_H
#define CSVDAO_H

#include <string>
#include <map>
#include <vector>
#include "util.h"
#include "globalConfig.h"

class CsvDao {
public:
	explicit CsvDao(const string &path);
	~CsvDao() = default;

protected:
	vector<map<string, string> > data;
	string content;
};

#endif // CSVDAO_H
