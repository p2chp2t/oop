#include <iostream>
#include <string>
#include <vector>
#include "artist.h"
#include "drawer.h"
using namespace std;

string drawer::draw() {
	string result = ""; //최종 ASCII 문자로 구성된 그림을 저장하는 string
	//좌표마다 mapper 함수 호출하여 ascii 문자로 변환 후 string에 추가
	for (int y = 0;y < p->get_height();y++) {
		for (int x = 0;x < p->get_width();x++) {
			char ascii = p->mapper(x, y);
			result += ascii;
		}
		result += "\n"; //한 행이 끝나면 개행 문자 추가
	}
	return result;
}

string downsample::draw() {
	string down_result = ""; //downsample된 그림을 저장하는 string
	int new_width = p->get_width() / 2; //절반이 된 너비와 높이
	int new_height = p->get_height() / 2;
	for (int y = 0;y < new_height;y++) {
		for (int x = 0;x < new_width;x++) {
			int new_x = x * 2; //짝수 x, y
			int new_y = y * 2;
			char ascii = p->mapper(new_x, new_y);
			down_result += ascii;
		}
		down_result += "\n"; //한 줄 끝나면 개행 문자 추가
	}
	return down_result;
}

string upsample::draw() {
	string up_result = ""; //upsample된 그림을 저장하는 string
	int new_width = p->get_width() * 2; //두배가 된 너비와 높이
	int new_height = p->get_height() * 2;
	for (int y = 0;y < new_height;y++) {
		for (int x = 0;x < new_width;x++) {
			int new_x = x / 2;
			int new_y = y / 2;
			char ascii = p->mapper(new_x, new_y);
			up_result += ascii;
		}
		up_result += "\n"; //한 줄 끝나면 개행 문자 추가
	}
	return up_result;
}

string scale::draw() {
	if (x_s == 0 || y_s == 0) {
		cout << "Invalid scale! (0)" << endl; //에러 처리
		return "";
	}
	//배율이 음의 정수인 경우 해당 값의 음의 역수를 배율로 사용
	if (x_s < 0) x_s = (-1.0) / x_s;
	if (y_s < 0) y_s = (-1.0) / y_s;
	string s_result = "";
	//배울에 맞게 조정한 너비와 높이
	int new_width = p->get_width() * x_s;
	int new_height = p->get_height() * y_s;
	for (int y = 0;y < new_height;y++) {
		for (int x = 0;x < new_width;x++) {
			int new_x = x / x_s;
			int new_y = y / y_s;
			char ascii = p->mapper(new_x, new_y);
			s_result += ascii;
		}
		s_result += "\n"; //한 줄 끝나면 개행 문자 추가
	}
	return s_result;
}
