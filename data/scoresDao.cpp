#include "scoresDao.h"

map<string, string> ScoresDao::getCourseIdAndScoreByStuId(const string &stuId) {
	map<string, string> m;
	for (auto &i : data) {
		if (i["stu_id"] == stuId) {
			m[i["course_id"]] = i["score"];
		}
	}
	return m;
}

map<string, string> ScoresDao::getStuIdAndScoreByCourseId(const string &courseId) {
	map<string, string> m;
	for (auto &i : data) {
		if (i["course_id"] == courseId) {
			m[i["stu_id"]] = i["score"];
		}
	}
	return m;
}

ScoresDao scoresDao("scores.csv");