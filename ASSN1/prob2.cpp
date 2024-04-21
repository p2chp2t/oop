/*PA1 문제2 학번: 20220041 이름: 김유진*/
#include <iostream>
#include <cstring> //strcmp 함수를 포함하는 헤더파일
#include <cmath> //수학 함수를 포함하는 헤더파일
#include <iomanip> //setprecision 함수를 포함하는 헤더파일
using namespace std;

void addNum(float a, float b);
void subNum(float a, float b);
void mulNum(float a, float b);
void divNum(float a, float b);
void sqrtNum(float a);
void squareNum(float a);
void printResult(float result);

int main() {
	char oper[10]; //연산자를 입력받는 char형 배열
	cin >> oper;
	float result; //결과값 저장하는 변수

	if (strcmp(oper, "+") == 0) { //덧셈
		float a, b;
		cin >> a >> b; //변수 2개 입력받음
		addNum(a, b);
	}
	else if (strcmp(oper, "-") == 0) { //뺄셈
		float a, b;
		cin >> a >> b;
		subNum(a, b);
	}
	else if (strcmp(oper, "*") == 0) { //곱셈
		float a, b;
		cin >> a >> b;
		mulNum(a, b);
	}
	else if (strcmp(oper, "/") == 0) { //나눗셈
		float a, b;
		cin >> a >> b;
		divNum(a, b);
	}
	else if (strcmp(oper, "sqrt") == 0) { //루트
		float a;
		cin >> a; //변수 하나만 입력받음
		sqrtNum(a);
	}
	else if (strcmp(oper, "square") == 0) { //제곱
		float a;
		cin >> a; //변수 하나만 입력받음
		squareNum(a);
	}
	return 0;
}

/*연산을 수행하고 값을 출력하는 함수들*/
void addNum(float a, float b) { //덧셈
	printResult(a + b);
}

void subNum(float a, float b) { //뺄셈
	printResult(a - b);
}

void mulNum(float a, float b) { //곱셈
	printResult(a * b);
}

void divNum(float a, float b) { //나눗셈
	printResult(a / b);
}

void sqrtNum(float a) { //제곱근
	printResult(sqrtf(a));
}

void squareNum(float a) { //제곱
	printResult(powf(a, 2));
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
