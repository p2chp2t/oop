#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "artist.h"
using namespace std;
//base class
class drawer {
protected:
	artist* p;
public:
	drawer(artist* ptr) //drawer 생성자
		:p(ptr) {}
	int width = p->get_width();
	int height = p->get_height();
	virtual string draw();
	virtual ~drawer() {}
};
//derived
class downsample :public drawer {
public:
	downsample(artist* ptr) :drawer(ptr) {} //생성자
	~downsample() {}
	string draw();
};

class upsample :public drawer {
public:
	upsample(artist* ptr) :drawer(ptr) {} //생성자
	~upsample() {}
	string draw();
};

class scale :public drawer {
private:
	double x_s; //x축 배율
	double y_s; //y축 배율
public:
	scale(artist* ptr, int xs, int ys) //생성자
		:drawer(ptr), x_s(xs), y_s(ys) {}
	~scale() {};
	string draw();
};