#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "parser.h"
using namespace std;

vector<int> parser::load_image(const char* input) {
	ifstream infile;
	vector<int> numbers; //파일에 적힌 숫자 저장하는 벡터
	int num;
	char c;
	infile.open(input);
	if (!infile.is_open()) { // 파일이 안 열린 경우 에러
		cout << "cannot open the file " << input << endl;
		return {};
	}
	while (!infile.eof()) { //파일 끝까지
		infile >> num;
		numbers.push_back(num);
		infile >> c;
		if (infile.fail()) {
			break;
		}
	}
	infile.close(); //파일 닫기
	return numbers;
}

vector<string> parser::load_config(const char* path) {
	ifstream infile;
	vector<string> words;
	string word;
	infile.open(path);
	if (!infile.is_open()) { //파일이 안 열린 경우 에러
		cout << "cannot open the file " << path << endl;
		return {};
	}
	char ch;
	while (!infile.eof()) {
		getline(infile, word, '|');
		if (!word.empty() && word.back() == '\n') {
			word.pop_back();
		}
		words.push_back(word);
	}
	infile.close(); //파일 닫기
	return words;
}

void parser::write_result(const char* path, const string& contents) {
	ofstream myfile;
	myfile.open(path);
	myfile << contents;
	myfile.close();
}