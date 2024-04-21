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
	artist(int _width, int _height, const vector<int>& _pixels) //artist 생성자
		:width(_width), height(_height), pixels(_pixels) {}
	int pixel_data(int, int); //pixel 값을 리턴하는 함수
	int get_width() { return width; } //width 값 리턴하는 함수
	int get_height() { return height; } //height 값 리턴하는 함수
	virtual char mapper(int, int) = 0; //pure virtual function
	virtual ~artist() {};
};
//derived
class classic :public artist {
public:
	classic(int _width, int _height, const vector<int>& _pixels) //classic 생성자
		:artist(_width, _height, _pixels) {}
	~classic() {}; //classic 소멸자
	char mapper(int, int);
};

class iclassic :public artist {
public:
	iclassic(int _width, int _height, const vector<int>& _pixels) //iclassic 생성자
		:artist(_width, _height, _pixels) {}
	~iclassic() {}; //iclassic 소멸자
	char mapper(int, int);
};

class sobelx :public artist {
private:
	int width;
public:
	sobelx(int _width, int _height, const vector<int>& _pixels) //sobelx 생성자
		:artist(_width, _height, _pixels), width(_width) {}
	~sobelx() {}; //sobelx 소멸자
	char mapper(int, int);
};

class sobely :public artist {
private:
	int height;
public:
	sobely(int _width, int _height, const vector<int>& _pixels) //sobely 생성자
		:artist(_width, _height, _pixels), height(_height) {}
	~sobely() {}; //sobely 소멸자
	char mapper(int, int);
};

class gradient :public artist {
private:
	int width;
	int height;
public:
	gradient(int _width, int _height, const vector<int>& _pixels) //gradient 생성자
		:artist(_width, _height, _pixels), width(_width), height(_height) {}
	~gradient() {}; //gradient 소멸자
	char mapper(int, int);
};