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

void student::input_info() { //학생의 정보를 입력받는 student class의 member function
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

bool student::is_valid() { //학생 데이터 input이 유효한지 확인하는 함수
	for (int i = 0;i < dept.size();i++) { //dept는 대문자만을 입력받는다
		if (dept[i] != toupper(dept[i])) return false;
	}
	if (gender != "F" && gender != "M") return false; //gender는 M, F만 입력 가능
	if (age < 18 || age > 30) return false; //age는 18 이상 30 이하
	return true;
}


