#pragma once
#include <iostream>
#include <string>
using namespace std;

string get_string() { //������ ���Ե��� ���� string�� �Է¹޴� �Լ�
	string input;
	while (1) {
		getline(cin, input);
		if (input.empty() || input.find(' ') != string::npos) { //�����̰ų� ���ڿ��� ������ �ִ� ���
			cout << "Invalid input." << endl;
		}
		else {
			return input;
		}
	}
}