#include "view.h"
#include <string>
#include <iostream>
#include "globalConfig.h"
#include "util.h"
#include <stdexcept>
using namespace std;

string View::render(ModelAndView &m) {
	string path = VIEW_PATH + m.pageName;
	// cout << "RENDERING: " << path << endl;
	string content = loadFile(path);
	for (auto it = m.args.begin(); it != m.args.end(); ++it) {
		string key   = it->first;
		string value = it->second;
		string tag   = "{{" + key + "}}";
		size_t pos   = content.find(tag);
		while (pos != string::npos) {
			content.replace(pos, tag.length(), value);
			pos = content.find(tag);
		}
	}
	if (content.find("{{each") != string::npos) {
		int beginPos       = content.find("}}", content.find("{{each")) + 2;
		int endPos         = content.find("{{/each}}");
		int rowNameBegin   = content.rfind(' ', beginPos) + 1;
		int rowNameEnd     = content.find("}}", content.find("{{each"));
		string rowName     = content.substr(rowNameBegin, rowNameEnd - rowNameBegin);
		string eachContent = content.substr(beginPos, endPos - beginPos);
		int insertPos      = endPos;
		for (auto it = m.table.begin(); it != m.table.end(); ++it) {
			string row = eachContent;
			for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
				string key   = it2->first;
				string value = it2->second;
				string tag   = "{{" + rowName + "." + key + "}}";
				size_t pos   = row.find(tag);
				while (pos != string::npos) {
					row.replace(pos, tag.length(), value);
					pos = row.find(tag);
				}
			}
			content.insert(insertPos, row);
			insertPos += row.length();
		}
		content.erase(beginPos, endPos - beginPos);
		content.erase(content.find("{{/each}}"), string("{{/each}}").length());
		content.erase(content.find("{{each"), beginPos - content.find("{{each"));
	}
	while (content.find("{{if") != string::npos) {
		int beginPos = content.find("}}", content.find("{{if")) + 1;
		int endPos   = content.find("{{/if}}");
		string ifExp = content.substr(content.find("{{if") + 5, beginPos - content.find("{{if") - 6);
		if (m.args.find(ifExp) != m.args.end()) {
			string tag = "{{" + ifExp + "}}";
			size_t pos = content.find(tag);
			while (pos != string::npos) {
				content.replace(pos, tag.length(), m.args[ifExp]);
				pos = content.find(tag);
			}
			content.erase(content.find("{{if"), beginPos - content.find("{{if") + 1);
			if (content.find("{{else}}") != string::npos) {
				content.erase(content.find("{{else}}"), content.find("{{/if}}") - content.find("{{else}}"));
			}
			content.erase(content.find("{{/if}}"), 7);
		} else {
			if (content.find("{{else}}", beginPos) != string::npos) {
				content.erase(content.find("{{if"), content.find("{{else}}") - content.find("{{if") + 8);
				content.erase(content.find("{{/if}}"), 7);
			} else
				content.erase(content.find("{{if"), endPos - content.find("{{if") + 7);
		}
	}
	if (content.find("{{") != string::npos) {
		throw runtime_error("500");
	}
	return content;
}
