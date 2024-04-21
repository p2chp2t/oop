#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//base class
class artist {
private:
	int width;
	int height;
	const vector<int> pixels;
public:
	artist(int _width, int _height, const vector<int>& _pixels) //artist ������
		:width(_width), height(_height), pixels(_pixels) {}
	int pixel_data(int, int); //pixel ���� �����ϴ� �Լ�
	int get_width() { return width; } //width �� �����ϴ� �Լ�
	int get_height() { return height; } //height �� �����ϴ� �Լ�
	virtual char mapper(int, int) = 0; //pure virtual function
	virtual ~artist() {};
};
//derived
class classic :public artist {
public:
	classic(int _width, int _height, const vector<int>& _pixels) //classic ������
		:artist(_width, _height, _pixels) {}
	~classic() {}; //classic �Ҹ���
	char mapper(int, int);
};

class iclassic :public artist {
public:
	iclassic(int _width, int _height, const vector<int>& _pixels) //iclassic ������
		:artist(_width, _height, _pixels) {}
	~iclassic() {}; //iclassic �Ҹ���
	char mapper(int, int);
};

class sobelx :public artist {
private:
	int width;
public:
	sobelx(int _width, int _height, const vector<int>& _pixels) //sobelx ������
		:artist(_width, _height, _pixels), width(_width) {}
	~sobelx() {}; //sobelx �Ҹ���
	char mapper(int, int);
};

class sobely :public artist {
private:
	int height;
public:
	sobely(int _width, int _height, const vector<int>& _pixels) //sobely ������
		:artist(_width, _height, _pixels), height(_height) {}
	~sobely() {}; //sobely �Ҹ���
	char mapper(int, int);
};

class gradient :public artist {
private:
	int width;
	int height;
public:
	gradient(int _width, int _height, const vector<int>& _pixels) //gradient ������
		:artist(_width, _height, _pixels), width(_width), height(_height) {}
	~gradient() {}; //gradient �Ҹ���
	char mapper(int, int);
};