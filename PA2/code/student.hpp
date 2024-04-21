#pragma once
#include <iostream>
#include <string>
using namespace std;

class student {
public:
	string dept, name, gender; 
	int age;
	student();
	void input_info();
	bool is_valid();
};

student::student() {
	dept = "";
	name = "";
	gender = "";
	age = 0;
}

void student::input_info() { //�л��� ������ �Է¹޴� student class�� member function
	cout << "Dept: ";
	dept = get_string();
	cout << "Gender: ";
	gender=get_string();
	cout << "Name: ";
	name = get_string();
	cout << "Age: ";
	cin >> age;
	cin.ignore(1024, '\n');
}

bool student::is_valid() { //�л� ������ input�� ��ȿ���� Ȯ���ϴ� �Լ�
	for (int i = 0;i < dept.size();i++) { //dept�� �빮�ڸ��� �Է¹޴´�
		if (dept[i] != toupper(dept[i])) return false;
	}
	if (gender != "F" && gender != "M") return false; //gender�� M, F�� �Է� ����
	if (age < 18 || age > 30) return false; //age�� 18 �̻� 30 ����
	return true;
}


