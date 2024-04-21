#include <iostream>
#include <string>
#include <vector>
#include "artist.h"
using namespace std;

int artist::pixel_data(int x, int y) {
	return pixels.at(y * width + x); //(x,y)에서의 pixel 값 리턴
}

char classic::mapper(int x, int y) {
	const int pixel = pixel_data(x, y);
	char carr[15] = { '@','&','%','W','X','A','H','O','T','*','^','+','-','.',' ' };
	int idx = pixel / 17;
	if (idx >= 0 && idx <= 14) return carr[idx];
	if (pixel == 255) return carr[14];
}

char iclassic::mapper(int x, int y) {
	const int pixel = pixel_data(x, y);
	char carr[15] = { '@','&','%','W','X','A','H','O','T','*','^','+','-','.',' ' };
	int idx = pixel / 17;
	if (idx >= 0 && idx <= 14) return carr[14 - idx];
	if (pixel == 255) return carr[0];
}

char sobelx::mapper(int x, int y) {
	if (x != (width - 1)) { //같은 행의 마지막 픽셀이 아닌 경우 
		int cur = pixel_data(x, y); //현재 픽셀
		int next = pixel_data(x + 1, y); //x축 양의 방향으로 인접한 픽셀
		if ((cur - next) >= 50 || (next - cur) >= 50) return '|';
	}
	return ' '; //'|'에 해당되는 경우가 아니라면 공백 문자
}

char sobely::mapper(int x, int y) {
	if (y != (height - 1)) { //같은 열의 마지막 픽셀이 아닌 경우
		int cur = pixel_data(x, y); //현재 픽셀
		int next = pixel_data(x, y + 1); //y축 양의 방향으로 인접한 픽셀
		if ((cur - next) >= 50 || (next - cur) >= 50) return '-';
	}
	return ' '; //'-'에 해당하는 경우가 아니라면 공백 문자
}

char gradient::mapper(int x, int y) {
	int cur = pixel_data(x, y); //현재 픽셀
	char c = ' ';
	if (x != (width - 1)) { //같은 행의 마지막 픽셀이 아닌 경우 
		int next = pixel_data(x + 1, y); //x축 양의 방향으로 인접한 픽셀
		if ((cur - next) >= 50 || (next - cur) >= 50) c = '|';
	}
	if (y != (height - 1)) { //같은 열의 마지막 픽셀이 아닌 경우
		int next = pixel_data(x, y + 1); //y축 양의 방향으로 인접한 픽셀
		if ((cur - next) >= 50 || (next - cur) >= 50) c = '-';
	}
	if (x != (width - 1) && y != (height - 1)) { //마지막 행이나 마지막 열에 있는 픽셀이 아닌 경우
		int x_next = pixel_data(x + 1, y);
		int y_next = pixel_data(x, y + 1);
		bool x_is = ((cur - x_next) >= 50 || (x_next - cur) >= 50);
		bool y_is = ((cur - y_next) >= 50 || (y_next - cur) >= 50);
		if (x_is == true && y_is == true) c = '+';
	}
	return c; //'|', '-', '+' 그 어느 것도 해당되지 않으면 공백 문자
}
