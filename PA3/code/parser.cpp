#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "parser.h"
using namespace std;

vector<int> parser::load_image(const char* input) {
	ifstream infile;
	vector<int> numbers; //���Ͽ� ���� ���� �����ϴ� ����
	int num;
	char c;
	infile.open(input);
	if (!infile.is_open()) { // ������ �� ���� ��� ����
		cout << "cannot open the file " << input << endl;
		return {};
	}
	while (!infile.eof()) { //���� ������
		infile >> num;
		numbers.push_back(num);
		infile >> c;
		if (infile.fail()) {
			break;
		}
	}
	infile.close(); //���� �ݱ�
	return numbers;
}

vector<string> parser::load_config(const char* path) {
	ifstream infile;
	vector<string> words;
	string word;
	infile.open(path);
	if (!infile.is_open()) { //������ �� ���� ��� ����
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
	infile.close(); //���� �ݱ�
	return words;
}

void parser::write_result(const char* path, const string& contents) {
	ofstream myfile;
	myfile.open(path);
	myfile << contents;
	myfile.close();
}