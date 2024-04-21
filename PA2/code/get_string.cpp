#pragma once
#include <iostream>
#include <string>
using namespace std;

string get_string() { //공백이 포함되지 않은 string을 입력받는 함수
	string input;
	while (1) {
		getline(cin, input);
		if (input.empty() || input.find(' ') != string::npos) { //공백이거나 문자열에 공백이 있는 경우
			cout << "Invalid input." << endl;
		}
		else {
			return input;
		}
	}
}
