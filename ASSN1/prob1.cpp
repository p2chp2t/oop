#include <iostream>
using namespace std;

void dec2bin(int n);
void dec2oct(int n);
void dec2hex(int n);

int main() {
	int decimal; //변환할 10진수 값
	int num; //변환할 진수
	cin >> decimal >> num;
	if (num == 2) //2진수 변환
		dec2bin(decimal);
	else if (num == 8) //8진수 변환
		dec2oct(decimal);
	else if (num == 16) //16진수 변환
		dec2hex(decimal);
	return 0;
}

void dec2bin(int n) { //10진수를 2진수로 변환해 출력하는 함수
	int binary[50]; //2진수(0, 1)을 저장하는 int형 배열
	int i = 0; //배열의 index
	while (n > 0) {
		binary[i] = n % 2; 
		i++;
		n /= 2;
	}
	for (int j = i - 1;j >= 0;j--) { //배열의 마지막 원소부터 역순으로 출력
		cout << binary[j];
	}
	return;
}

void dec2oct(int n) { //10진수를 8진수로 변환하는 함수
	int octal[50]; //8진수를 저장하는 int형 배열
	int i = 0;
	while (n > 0) {
		octal[i] = n % 8;
		i++;
		n /= 8;
	}
	for (int j = i - 1;j >= 0;j--) {
		cout << octal[j];
	}
	return;
}

void dec2hex(int n) { //10진수를 16진수로 변환하는 함수
	char hex[50]; //16진수를 저장하는 char형 배열
	int i = 0;
	while (n > 0) {
		int rem = n % 16; //16으로 나눴을 떄의 나머지를 저장하는 변수
		if (rem < 10) //0~9까지
			hex[i] = rem + 48;
		else //A(10) B(11) ... F(15)
			hex[i] = rem + 55;
		i++;
		n /= 16;
	}
	for (int j = i - 1;j >= 0;j--) {
		cout << hex[j];
	}
	return;
}
