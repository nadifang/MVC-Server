#include "csvDao.h"

CsvDao::CsvDao(const string &path) {
	content              = loadFile(DATA_PATH + path);
	vector<string> lines = split(content, '\n');
	vector<string> keys  = split(lines[0], ',');
	for (int i = 1; i < lines.size(); ++i) {
		vector<string> values = split(lines[i], ',');
		map<string, string> m;
		for (int j = 0; j < keys.size(); ++j) {
			m[keys[j]] = values[j];
		}
		data.push_back(m);
	}
}
