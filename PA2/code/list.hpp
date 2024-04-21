#pragma once
#include <iostream>
#include <string>
using namespace std;

class list { //전체 학생 정보를 저장하는 하나의 list
public:
	int count, dept_cnt; //list 내 존재하는 node의 개수, list 내 존재하는 학과의 개수
	string dept[9]; //학과를 저장하는 string array
	node* head; //linked list의 head

	list();
	~list();
	void swapNode(student& n1, student& n2);
	bool compare(string metric, student s1, student s2);
	void sort(string metric);

	void print_list();

	void save_node(node* n);
	void delete_node(node* n);
	bool is_student(student s);
	bool dept_arr(student s);
	void add_student();
	void del_student();

	void avg_pivot(string metric, int count);
	void max_pivot(string metric, int count);
	void min_pivot(string metric, int count);
	void pivot_list();
};

list::list() { //list의 생성자
	count = 0;
	dept_cnt = 0;
	for (int i = 0;i < 9;i++) dept[i] = "";
	head = NULL;
}

list::~list() { //list의 소멸자
	node* pDelete;
	node* pTemp;
	pDelete = head;
	while (pDelete != NULL) {
		pTemp = pDelete->next;
		delete pDelete;
		pDelete = pTemp;
	}
	head = NULL;
}

void list::swapNode(student& n1, student& n2) { //node 데이터를 swap해주는 함수
	student temp = n1;
	n1 = n2;
	n2 = temp;
	return;
}

bool list::compare(string metric, student s1, student s2) { // metric을 기준으로 s1이 s2 앞에 와야할 때 true를 반환하는 함수
	if (metric == "default") {
		if (s1.dept < s2.dept) return true;
		else if (s1.dept > s2.dept) return false;

		if (s1.gender < s2.gender) return true;
		else if (s1.gender > s2.gender) return false;

		if (s1.name < s2.name) return true;
		else if (s1.name > s2.name) return false;

		return s1.age <= s2.age;
	}
	else if (metric == "dept") {
		return s1.dept < s2.dept;
	}
	else if (metric == "gender") {
		return s1.gender < s2.gender;
	}
	else if (metric == "dept+gender") {
		if (s1.dept < s2.dept) return true;
		else if (s1.dept > s2.dept) return false;
		return s1.gender < s2.gender;
	}
	else return false;
}

void list::sort(string metric) { //list를 metric을 기준으로 정렬하는 함수
	if (metric == "default" || metric == "dept" || metric == "gender" || metric == "dept+gender") { //list 전체 정렬
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL && cur->next != NULL) {
				if (compare(metric, cur->data, cur->next->data) == false) { // cur와 cur->next를 바꿔야하는 경우 node간 swap 진행
					swapNode(cur->data, cur->next->data);
				}
				cur = cur->next;
			}
		}
	}
	else {
		cout << "Invalid metric: " << metric << endl;
	}
	return;
}

void list::print_list() { //list 내의 학생 정보를 출력하는 list class의 member function
	cout << "Dept\tGender\tName\tAge" << endl; //index 출력
	sort("default");
	if (count == 0) return; //list가 비어있는 경우
	node* temp = head;
	while (temp != NULL) { //list의 원소를 하나씩 출력하는 반복문
		cout << temp->data.dept << "\t" << temp->data.gender << "\t" << temp->data.name << "\t" << temp->data.age << endl;
		temp = temp->next;
	}
	return;
}

void list::save_node(node* n) { //linked list에 node를 저장하는 함수
	if (head == NULL && count == 0) { //linked list가 비어있는 경우
		head = n;
	}
	else {
		node* temp = head;
		while (temp->next != NULL) { //마지막 node를 찾는 반복문
			temp = temp->next;
		}
		temp->next = n; //마지막 node의 다음 node에 새로운 node 추가
	}
}

void list::delete_node(node* n) { //linked list에 node를 삭제하는 함수
	if (count == 0 || head == NULL) { //linked list가 비어있는 경우
		cout << "Can't Delete it." << endl;
		return;
	}
	else if (head == n) { //삭제하려는 node가 head인 경우
		head = head->next;
		delete n;
		n = NULL;
	}
	else {
		node* temp = head;
		while (temp->next != NULL) {
			if (temp->next == n) { //삭제하려는 node 찾으면 반복문 탈출
				temp->next = n->next; //삭제할 node의 전 node와 후 node를 연결한다.
				delete n;
				n = NULL;
				return;
			}
			temp = temp->next;
		}
	}
}

bool list::is_student(student s) { //입력받은 학생 정보와 동일한 학생이 있는지 확인하는 함수
	bool result = false;
	node* cur = head;
	while (cur != NULL) { //list에 중복되는 학생이 있는지 확인하는 반복문
		if (s.dept == cur->data.dept && s.gender == cur->data.gender //list에 이미 존재하는 학생을 입력하는 경우
			&& s.name == cur->data.name && s.age == cur->data.age) {
			return result = true; //찾는 학생이 있으면 true 반환
		}
		cur = cur->next;
	}
	return result; //찾는 학생이 없으면 false 반환
}

bool list::dept_arr(student s) { //학과 수 갱신 및 dept 배열에 저장
	bool is_dept = false; //dept 배열에 이미 저장된 dept인지 확인하는 변수
	for (int i = 0;i < dept_cnt;i++) {
		if (dept[i] == s.dept) {
			is_dept = true;
			break;
		}
	}
	if (!is_dept && dept_cnt < 9) { //dept 배열에 저장
		dept_cnt++;
		dept[dept_cnt - 1] = s.dept;
	}
	else if (!is_dept && dept_cnt >= 9) {
		return false; //에러발생하면 false 반환
	}
	//dept배열을 사전순서대로 정렬
	for (int i = 0;i < dept_cnt-1;i++) {
		if (dept[i] > dept[i + 1]) { //swap 진행
			string temp = dept[i];
			dept[i] = dept[i + 1];
			dept[i + 1] = temp;
		}
	}
	return true; //정상적으로 dept array 채웠으면 true 반환
}

void list::add_student() { //학생 데이터를 추가하는 함수
	node* pNew = new node;
	student temp;
	while (1) {
		temp.input_info();
		if (temp.is_valid()) { //유효한 값일 때
			break;
		}
		cout << "Invalid student data. Try again." << endl;
	}

	if (is_student(temp) == true) { //list에 중복되는 학생이 있는 경우
		cout << "The student already exists." << endl;
		return;
	}
	
	//pNew로 temp의 데이터 옮기기
	pNew->data.dept = temp.dept;
	pNew->data.gender = temp.gender;
	pNew->data.name = temp.name;
	pNew->data.age = temp.age;
	save_node(pNew); //pNew node 추가
	count++;
	bool result = dept_arr(pNew->data);
	if (!result) {
		cout << "Error: dept array is full!!" << endl;
		delete_node(pNew);
		count--;
		return;
	}
	cout << "A student is added in table!" << endl;
	return;
}

void list::del_student() { //학생을 삭제하는 함수
	student s;
	s.input_info(); //삭제할 학생 정보 입력받기

	if (is_student(s) == true) { //list에 삭제할 학생이 있는 경우
		node* cur = head;

		int same_dept = 0; //list에 같은 학과의 학생이 몇명인지 확인
		node* cur2 = head;
		while (cur2 != NULL) {
			if (cur2->data.dept == s.dept) { //s와 같은 학과의 학생인 경우 same_dept 1씩 추가
				same_dept++;
			}
			cur2 = cur2->next;
		}
		bool only_dept = (same_dept == 1); //list에 해당 학과의 학생이 오직 한명인 경우 true 반환
		if (only_dept) { //그 학생이 속한 학과에 다른 학생이 없는 경우
			//학과 삭제
			for (int i = 0;i < dept_cnt;i++) {
				if (dept[i] == s.dept) { //삭제할 학과 찾기
					for (int j = i;j < dept_cnt;j++) {
						if (j == dept_cnt - 1) { //비우기
							dept[j] = "";
						}
						else {
							dept[j] = dept[j + 1];
						}
					}
					dept_cnt--;
					break;
				}
			}
		}
		while (cur != NULL) {
			if (cur->data.dept == s.dept && cur->data.gender == s.gender //list에 삭제할 학생이 존재하는 경우
				&& cur->data.name == s.name && cur->data.age == s.age) {
				delete_node(cur);
				count--;
				break;
			}
			cur = cur->next;
		}
		cout << "Deleted!!" << endl;
	}
	else {
		cout << "Can't Delete it." << endl;
	}
	return;
}

void list::pivot_list() {
	//카테고리 및 함수 입력 받기
	int category = 0, func = 0;
	cout << "----------Category----------" << endl;
	cout << "1. Dept" << endl;
	cout << "2. Gender" << endl;
	cout << "3. Dept and Gender" << endl;
	cout << "----------------------------" << endl;
	cout << "Selection: ";
	cin >> category;
	
	cout << "----------Function----------" << endl;
	cout << "1. Average" << endl;
	cout << "2. Max" << endl;
	cout << "3. Min" << endl;
	cout << "----------------------------" << endl;
	cout << "Selection: ";
	cin >> func;
	cin.ignore(1024, '\n');

	//테이블 index 출력
	string index;
	if (category == 1) index += "Dept\t";
	else if (category == 2) index += "Gender\t";
	else if (category == 3) index += "Dept\tGender\t";
	if (func == 1) index += "Average";
	else if (func == 2) index += "Max";
	else if (func == 3) index += "Min";
	cout << index << endl;

	if (category == 1) {//dept를 기준으로 pivot
		sort("dept");
		if (func == 1) { //average 출력
			avg_pivot("dept", dept_cnt);
		}
		else if (func == 2) { //max 출력
			max_pivot("dept", dept_cnt);
		}
		else if (func == 3) { //min 출력
			min_pivot("dept", dept_cnt);
		}
		else
			cout << "Invalid function!" << endl;
	}
	else if (category == 2) { //gender를 기준으로 pivot
		sort("gender");
		if (func == 1) { //average
			avg_pivot("gender", 2);
		}
		else if (func == 2) { //max
			max_pivot("gender", 2);
		}
		else if (func == 3) { //min
			min_pivot("gender", 2);
		}
		else cout << "Invalid function!" << endl;
	}
	else if (category == 3) { //dept와 gender를 기준으로 pivot
		sort("dept+gender");
		if (func == 1) { //average
			avg_pivot("dept+gender", dept_cnt);
		}
		else if (func == 2) { //max
			max_pivot("dept+gender", dept_cnt);
		}
		else if (func == 3) { //min
			min_pivot("dept+gender", dept_cnt);
		}
		else cout << "Invalid function!" << endl;
	}
	else cout << "Invalid category!" << endl;
	return;
}

void list::avg_pivot(string metric, int count) { //피벗 변환해 average 계산하는 함수
	if (count == 0) return;
	int* sum_arr = new int[count] {0, }; //같은 학과 학생들의 나이의 합을 저장하는 배열
	int* cnt_arr = new int[count] {0, }; //같은 학과인 학생들의 수를 저장하는 배열
	double* avg_arr = new double[count] {0.0, }; //같은 학과인 학생들 나이의 평균을 저장하는 배열

	if (metric == "dept") { //avg_pivot("dept",dept_cnt)
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) {
					sum_arr[i] += cur->data.age;
					cnt_arr[i]++;
				}
				cur = cur->next;
			}
			if (cnt_arr[i] == 0) continue; //학생 수가 0이면 출력하지 않는다.
			avg_arr[i] = (double)sum_arr[i] / cnt_arr[i];
			cout << fixed;
			cout.precision(1); //소수점 한자리까지 반올림
			cout << dept[i] << "\t" << avg_arr[i] << endl;
		}
	}

	else if (metric == "gender") { //avg_pivot("gender",2)
		string gender[2] = {"F","M"};
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.gender == gender[i]) {
					sum_arr[i] += cur->data.age;
					cnt_arr[i]++;
				}
				cur = cur->next;
			}
			if (cnt_arr[i] == 0) continue; //학생 수가 0이면 출력하지 않는다.
			avg_arr[i] = (double)sum_arr[i] / cnt_arr[i];
			cout << fixed;
			cout.precision(1); //소수점 한자리까지 반올림
			cout << gender[i] << "\t" << avg_arr[i] << endl;
		}
	}

	else if (metric == "dept+gender") { //avg_pivot("dept+gender",dept_cnt)
		//2차원 배열 동적할당
		int** dept_gen_sum = new int* [count]; //같은 학과와 같은 성별 내 학생들의 나이 합을 저장하는 2차원 배열
		int** dept_gen_cnt = new int* [count]; //같은 학과와 같은 성별 내 학생들의 수를 저장하는 2차원 배열
		double** dept_gen_avg = new double* [count]; //같은 학과와 같은 성별 내 학생들 나이의 평균을 저장하는 2차원 배열
		for (int i = 0;i < count;i++) { 
			dept_gen_sum[i] = new int [2] {0};
			dept_gen_cnt[i] = new int[2] {0};
			dept_gen_avg[i] = new double[2] {0.0};
		}

		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) { //dept[i]에 해당하는 학과인 경우
					if (cur->data.gender == "F") { //해당 학과의 여학생인 경우
						dept_gen_sum[i][0] += cur->data.age;
						dept_gen_cnt[i][0]++;
					} 
					else if (cur->data.gender == "M") { //해당 학과의 남학생인 경우
						dept_gen_sum[i][1] += cur->data.age;
						dept_gen_cnt[i][1]++;
					}
				}
				cur = cur->next;
			}
			for (int j = 0;j < 2;j++) {
				if (dept_gen_cnt[i][j] == 0) continue;
				dept_gen_avg[i][j] = (double)dept_gen_sum[i][j] / dept_gen_cnt[i][j];
				cout << dept[i] << "\t";
				cout << fixed;
				cout.precision(1); //소수점 한자리까지 반올림
				if (j == 0) cout << "F\t" << dept_gen_avg[i][j] << endl;
				else cout << "M\t" << dept_gen_avg[i][j] << endl;
			}
		}
		//2차원 배열 동적할당 해제
		for (int i = 0;i < count;i++) {
			delete[] dept_gen_sum[i];
			delete[] dept_gen_cnt[i];
			delete[] dept_gen_avg[i];
		}
		delete[] dept_gen_sum;
		delete[] dept_gen_cnt;
		delete[] dept_gen_avg;
	}
	//배열 동적할당 해제
	delete[] sum_arr;
	delete[] cnt_arr;
	delete[] avg_arr;
	return;
}

void list::max_pivot(string metric, int count) { //피벗 변환 후 max 값 출력하는 함수
	if (count == 0) return;
	int* max_arr = new int[count] {0, }; //metric을 기준으로 pivot했을 때 max 결과값 저장하는 1차원 배열
	if (metric == "dept") { //max_pivot("dept", dept_cnt)
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) {
					if (cur->data.age > max_arr[i]) //최대값보다 크면 최대값 갱신
						max_arr[i] = cur->data.age;
				}
				cur = cur->next;
			}
			cout << dept[i] << "\t" << max_arr[i] << endl;
		}
	}
	else if (metric == "gender") { //max_pivot("gender",2)
		string gender[2] = {"F", "M"};
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.gender == gender[i]) {
					if (cur->data.age > max_arr[i]) //최대값보다 크면 최대값 갱신
						max_arr[i] = cur->data.age;
				}
				cur = cur->next;
			}
			cout << gender[i] << "\t" << max_arr[i] << endl;
		}
	}
	else if (metric == "dept+gender") { //max_pivot("dept+gender",dept_cnt)
		//2차원 배열 동적할당
		int** dept_gen_max = new int* [count]; //같은 학과와 같은 성별 내 학생들 나이의 max를 저장하는 2차원 배열
		for (int i = 0;i < count;i++) {
			dept_gen_max[i] = new int[2] {0, };
		}
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) { //dept[i]에 해당하는 학과인 경우
					if (cur->data.gender == "F") { //해당 학과의 여학생인 경우
						if (cur->data.age > dept_gen_max[i][0]) //최대값보다 큰 경우 최대값 갱신
							dept_gen_max[i][0] = cur->data.age;
					}
					else if (cur->data.gender == "M") { //해당 학과의 남학생인 경우
						if (cur->data.age > dept_gen_max[i][1]) //최대값보다 큰 경우 최대값 갱신
							dept_gen_max[i][1] = cur->data.age;
					}
				}
				cur = cur->next;
			}
			for (int j = 0;j < 2;j++) {
				if (dept_gen_max[i][j] == 0) continue; //학생 수가 0이면 출력하지 않는다.
				cout << dept[i] << "\t";
				if (j == 0) cout << "F\t" << dept_gen_max[i][j] << endl;
				else cout << "M\t" << dept_gen_max[i][j] << endl;
			}
		}
		//2차원 배열 동적할당 해제
		for (int i = 0;i < count;i++) {
			delete[] dept_gen_max[i];
		}
		delete[] dept_gen_max;
	}
	delete[] max_arr;
	return;
}

void list::min_pivot(string metric, int count) {
	if (count == 0) return;
	int* min_arr = new int[count]; //metric을 기준으로 pivot했을 때 min 결과값 저장하는 1차원 배열
	for (int i = 0;i < count;i++) { //배열 초기화
		min_arr[i] = 1000;
	}
	if (metric == "dept") { //min_pivot("dept", dept_cnt)
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) {
					if (cur->data.age < min_arr[i]) //최소값보다 작으면 최소값 갱신
						min_arr[i] = cur->data.age;
				}
				cur = cur->next;
			}
			cout << dept[i] << "\t" << min_arr[i] << endl;
		}
	}
	else if (metric == "gender") { //min_pivot("gender",2)
		string gender[2] = { "F", "M" };
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.gender == gender[i]) {
					if (cur->data.age < min_arr[i]) //최대값보다 크면 최대값 갱신
						min_arr[i] = cur->data.age;
				}
				cur = cur->next;
			}
			cout << gender[i] << "\t" << min_arr[i] << endl;
		}
	}
	else if (metric == "dept+gender") { //min_pivot("dept+gender",dept_cnt)
		//2차원 배열 동적할당
		int** dept_gen_min = new int* [count]; //같은 학과와 같은 성별 내 학생들 나이의 min을 저장하는 2차원 배열
		for (int i = 0;i < count;i++) {
			dept_gen_min[i] = new int[2];
		}
		for (int i = 0;i < count;i++) { //배열 초기화
			for (int j = 0;j < 2;j++) {
				dept_gen_min[i][j] = 100;
			}
		}
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) { //dept[i]에 해당하는 학과인 경우
					if (cur->data.gender == "F") { //해당 학과의 여학생인 경우
						if (cur->data.age < dept_gen_min[i][0]) //최소값보다 작은 경우 최소값 갱신
							dept_gen_min[i][0] = cur->data.age;
					}
					else if (cur->data.gender == "M") { //해당 학과의 남학생인 경우
						if (cur->data.age < dept_gen_min[i][1]) //최소값보다 작은 경우 최소값 갱신
							dept_gen_min[i][1] = cur->data.age;
					}
				}
				cur = cur->next;
			}
			for (int j = 0;j < 2;j++) {
				if (dept_gen_min[i][j] == 0) continue; //학생 수가 0이면 출력하지 않는다.
				cout << dept[i] << "\t";
				if (j == 0) cout << "F\t" << dept_gen_min[i][j] << endl;
				if (j == 1) cout << "M\t" << dept_gen_min[i][j] << endl;
			}
		}
		//2차원 배열 동적할당 해제
		for (int i = 0;i < count;i++) {
			delete[] dept_gen_min[i];
		}
		delete[] dept_gen_min;
	}
	delete[] min_arr;
	return;
}