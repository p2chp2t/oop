#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int toDec(string str);
void addNum(int a, int b);
void subNum(int a, int b);
void mulNum(int a, int b);
void divNum(int a, int b);
void printResult(float result);

int main() {
	char oper; //연산자를 입력받는 변수
	string n1, n2; //2개의 숫자를 입력받는 변수
	cin >> oper >> n1 >> n2;

	int dec1, dec2; //입력받은 숫자를 10진수로 변환하여 저장하는 변수
	dec1 = toDec(n1);
	dec2 = toDec(n2);

	if (oper == '+')
		addNum(dec1, dec2);
	else if (oper == '-')
		subNum(dec1, dec2);
	else if (oper == '*')
		mulNum(dec1, dec2);
	else if (oper == '/') {
		divNum(dec1, dec2);
	}

	return 0;
}

/*입력받은 변수를 10진수로 변환하는 함수*/
int toDec(string str) {
	int dec = 0;
	int base = 0; //몇 진수인지

	if (str.substr(0, 2) == "0b") { //binary
		str = str.substr(2);
		base = 2;
	}
	else if (str.substr(0, 2) == "0X") { //hexadecimal
		str = str.substr(2);
		base = 16;
	}
	else if (str.substr(0, 1) == "0") { //octal
		str = str.substr(1);
		base = 8;
	}
	dec = stoi(str, nullptr, base); //10진수로 변환하기
	return dec;
}

/*연산을 수행하고 값을 출력하는 함수들*/
void addNum(int a, int b) { //덧셈
	printResult(a + b);
}

void subNum(int a, int b) { //뺄셈
	printResult(a - b);
}

void mulNum(int a, int b) { //곱셈
	printResult(a * b);
}

void divNum(int a, int b) { //나눗셈
	printResult((float)a / b);
}

/*결과를 출력하는 함수*/
void printResult(float result) {
	if (result == static_cast<int>(result)) { //reuslt의 값이 정수인 경우
		cout << static_cast<int>(result) << endl;
	}
	else //result 값이 소수인 경우
		cout << fixed << setprecision(3) << result << endl; //소수점 셋째자리까지 반올림해서 나타내기
	return;
}
