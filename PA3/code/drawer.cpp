#include <iostream>
#include <string>
#include <vector>
#include "artist.h"
#include "drawer.h"
using namespace std;

string drawer::draw() {
	string result = ""; //���� ASCII ���ڷ� ������ �׸��� �����ϴ� string
	//��ǥ���� mapper �Լ� ȣ���Ͽ� ascii ���ڷ� ��ȯ �� string�� �߰�
	for (int y = 0;y < p->get_height();y++) {
		for (int x = 0;x < p->get_width();x++) {
			char ascii = p->mapper(x, y);
			result += ascii;
		}
		result += "\n"; //�� ���� ������ ���� ���� �߰�
	}
	return result;
}

string downsample::draw() {
	string down_result = ""; //downsample�� �׸��� �����ϴ� string
	int new_width = p->get_width() / 2; //������ �� �ʺ�� ����
	int new_height = p->get_height() / 2;
	for (int y = 0;y < new_height;y++) {
		for (int x = 0;x < new_width;x++) {
			int new_x = x * 2; //¦�� x, y
			int new_y = y * 2;
			char ascii = p->mapper(new_x, new_y);
			down_result += ascii;
		}
		down_result += "\n"; //�� �� ������ ���� ���� �߰�
	}
	return down_result;
}

string upsample::draw() {
	string up_result = ""; //upsample�� �׸��� �����ϴ� string
	int new_width = p->get_width() * 2; //�ι谡 �� �ʺ�� ����
	int new_height = p->get_height() * 2;
	for (int y = 0;y < new_height;y++) {
		for (int x = 0;x < new_width;x++) {
			int new_x = x / 2;
			int new_y = y / 2;
			char ascii = p->mapper(new_x, new_y);
			up_result += ascii;
		}
		up_result += "\n"; //�� �� ������ ���� ���� �߰�
	}
	return up_result;
}

string scale::draw() {
	if (x_s == 0 || y_s == 0) {
		cout << "Invalid scale! (0)" << endl; //���� ó��
		return "";
	}
	//������ ���� ������ ��� �ش� ���� ���� ������ ������ ���
	if (x_s < 0) x_s = (-1.0) / x_s;
	if (y_s < 0) y_s = (-1.0) / y_s;
	string s_result = "";
	//��￡ �°� ������ �ʺ�� ����
	int new_width = p->get_width() * x_s;
	int new_height = p->get_height() * y_s;
	for (int y = 0;y < new_height;y++) {
		for (int x = 0;x < new_width;x++) {
			int new_x = x / x_s;
			int new_y = y / y_s;
			char ascii = p->mapper(new_x, new_y);
			s_result += ascii;
		}
		s_result += "\n"; //�� �� ������ ���� ���� �߰�
	}
	return s_result;
}
