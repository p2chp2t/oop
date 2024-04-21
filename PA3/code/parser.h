#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class parser {
public:
	vector<int> load_image(const char*);
	vector<string> load_config(const char*);
	void write_result(const char*, const string&);
};