#pragma once
#include <iostream>
#include <string>
using namespace std;

class list { //��ü �л� ������ �����ϴ� �ϳ��� list
public:
	int count, dept_cnt; //list �� �����ϴ� node�� ����, list �� �����ϴ� �а��� ����
	string dept[9]; //�а��� �����ϴ� string array
	node* head; //linked list�� head

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

list::list() { //list�� ������
	count = 0;
	dept_cnt = 0;
	for (int i = 0;i < 9;i++) dept[i] = "";
	head = NULL;
}

list::~list() { //list�� �Ҹ���
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

void list::swapNode(student& n1, student& n2) { //node �����͸� swap���ִ� �Լ�
	student temp = n1;
	n1 = n2;
	n2 = temp;
	return;
}

bool list::compare(string metric, student s1, student s2) { // metric�� �������� s1�� s2 �տ� �;��� �� true�� ��ȯ�ϴ� �Լ�
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

void list::sort(string metric) { //list�� metric�� �������� �����ϴ� �Լ�
	if (metric == "default" || metric == "dept" || metric == "gender" || metric == "dept+gender") { //list ��ü ����
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL && cur->next != NULL) {
				if (compare(metric, cur->data, cur->next->data) == false) { // cur�� cur->next�� �ٲ���ϴ� ��� node�� swap ����
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

void list::print_list() { //list ���� �л� ������ ����ϴ� list class�� member function
	cout << "Dept\tGender\tName\tAge" << endl; //index ���
	sort("default");
	if (count == 0) return; //list�� ����ִ� ���
	node* temp = head;
	while (temp != NULL) { //list�� ���Ҹ� �ϳ��� ����ϴ� �ݺ���
		cout << temp->data.dept << "\t" << temp->data.gender << "\t" << temp->data.name << "\t" << temp->data.age << endl;
		temp = temp->next;
	}
	return;
}

void list::save_node(node* n) { //linked list�� node�� �����ϴ� �Լ�
	if (head == NULL && count == 0) { //linked list�� ����ִ� ���
		head = n;
	}
	else {
		node* temp = head;
		while (temp->next != NULL) { //������ node�� ã�� �ݺ���
			temp = temp->next;
		}
		temp->next = n; //������ node�� ���� node�� ���ο� node �߰�
	}
}

void list::delete_node(node* n) { //linked list�� node�� �����ϴ� �Լ�
	if (count == 0 || head == NULL) { //linked list�� ����ִ� ���
		cout << "Can't Delete it." << endl;
		return;
	}
	else if (head == n) { //�����Ϸ��� node�� head�� ���
		head = head->next;
		delete n;
		n = NULL;
	}
	else {
		node* temp = head;
		while (temp->next != NULL) {
			if (temp->next == n) { //�����Ϸ��� node ã���� �ݺ��� Ż��
				temp->next = n->next; //������ node�� �� node�� �� node�� �����Ѵ�.
				delete n;
				n = NULL;
				return;
			}
			temp = temp->next;
		}
	}
}

bool list::is_student(student s) { //�Է¹��� �л� ������ ������ �л��� �ִ��� Ȯ���ϴ� �Լ�
	bool result = false;
	node* cur = head;
	while (cur != NULL) { //list�� �ߺ��Ǵ� �л��� �ִ��� Ȯ���ϴ� �ݺ���
		if (s.dept == cur->data.dept && s.gender == cur->data.gender //list�� �̹� �����ϴ� �л��� �Է��ϴ� ���
			&& s.name == cur->data.name && s.age == cur->data.age) {
			return result = true; //ã�� �л��� ������ true ��ȯ
		}
		cur = cur->next;
	}
	return result; //ã�� �л��� ������ false ��ȯ
}

bool list::dept_arr(student s) { //�а� �� ���� �� dept �迭�� ����
	bool is_dept = false; //dept �迭�� �̹� ����� dept���� Ȯ���ϴ� ����
	for (int i = 0;i < dept_cnt;i++) {
		if (dept[i] == s.dept) {
			is_dept = true;
			break;
		}
	}
	if (!is_dept && dept_cnt < 9) { //dept �迭�� ����
		dept_cnt++;
		dept[dept_cnt - 1] = s.dept;
	}
	else if (!is_dept && dept_cnt >= 9) {
		return false; //�����߻��ϸ� false ��ȯ
	}
	//dept�迭�� ����������� ����
	for (int i = 0;i < dept_cnt-1;i++) {
		if (dept[i] > dept[i + 1]) { //swap ����
			string temp = dept[i];
			dept[i] = dept[i + 1];
			dept[i + 1] = temp;
		}
	}
	return true; //���������� dept array ä������ true ��ȯ
}

void list::add_student() { //�л� �����͸� �߰��ϴ� �Լ�
	node* pNew = new node;
	student temp;
	while (1) {
		temp.input_info();
		if (temp.is_valid()) { //��ȿ�� ���� ��
			break;
		}
		cout << "Invalid student data. Try again." << endl;
	}

	if (is_student(temp) == true) { //list�� �ߺ��Ǵ� �л��� �ִ� ���
		cout << "The student already exists." << endl;
		return;
	}
	
	//pNew�� temp�� ������ �ű��
	pNew->data.dept = temp.dept;
	pNew->data.gender = temp.gender;
	pNew->data.name = temp.name;
	pNew->data.age = temp.age;
	save_node(pNew); //pNew node �߰�
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

void list::del_student() { //�л��� �����ϴ� �Լ�
	student s;
	s.input_info(); //������ �л� ���� �Է¹ޱ�

	if (is_student(s) == true) { //list�� ������ �л��� �ִ� ���
		node* cur = head;

		int same_dept = 0; //list�� ���� �а��� �л��� ������� Ȯ��
		node* cur2 = head;
		while (cur2 != NULL) {
			if (cur2->data.dept == s.dept) { //s�� ���� �а��� �л��� ��� same_dept 1�� �߰�
				same_dept++;
			}
			cur2 = cur2->next;
		}
		bool only_dept = (same_dept == 1); //list�� �ش� �а��� �л��� ���� �Ѹ��� ��� true ��ȯ
		if (only_dept) { //�� �л��� ���� �а��� �ٸ� �л��� ���� ���
			//�а� ����
			for (int i = 0;i < dept_cnt;i++) {
				if (dept[i] == s.dept) { //������ �а� ã��
					for (int j = i;j < dept_cnt;j++) {
						if (j == dept_cnt - 1) { //����
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
			if (cur->data.dept == s.dept && cur->data.gender == s.gender //list�� ������ �л��� �����ϴ� ���
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
	//ī�װ� �� �Լ� �Է� �ޱ�
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

	//���̺� index ���
	string index;
	if (category == 1) index += "Dept\t";
	else if (category == 2) index += "Gender\t";
	else if (category == 3) index += "Dept\tGender\t";
	if (func == 1) index += "Average";
	else if (func == 2) index += "Max";
	else if (func == 3) index += "Min";
	cout << index << endl;

	if (category == 1) {//dept�� �������� pivot
		sort("dept");
		if (func == 1) { //average ���
			avg_pivot("dept", dept_cnt);
		}
		else if (func == 2) { //max ���
			max_pivot("dept", dept_cnt);
		}
		else if (func == 3) { //min ���
			min_pivot("dept", dept_cnt);
		}
		else
			cout << "Invalid function!" << endl;
	}
	else if (category == 2) { //gender�� �������� pivot
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
	else if (category == 3) { //dept�� gender�� �������� pivot
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

void list::avg_pivot(string metric, int count) { //�ǹ� ��ȯ�� average ����ϴ� �Լ�
	if (count == 0) return;
	int* sum_arr = new int[count] {0, }; //���� �а� �л����� ������ ���� �����ϴ� �迭
	int* cnt_arr = new int[count] {0, }; //���� �а��� �л����� ���� �����ϴ� �迭
	double* avg_arr = new double[count] {0.0, }; //���� �а��� �л��� ������ ����� �����ϴ� �迭

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
			if (cnt_arr[i] == 0) continue; //�л� ���� 0�̸� ������� �ʴ´�.
			avg_arr[i] = (double)sum_arr[i] / cnt_arr[i];
			cout << fixed;
			cout.precision(1); //�Ҽ��� ���ڸ����� �ݿø�
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
			if (cnt_arr[i] == 0) continue; //�л� ���� 0�̸� ������� �ʴ´�.
			avg_arr[i] = (double)sum_arr[i] / cnt_arr[i];
			cout << fixed;
			cout.precision(1); //�Ҽ��� ���ڸ����� �ݿø�
			cout << gender[i] << "\t" << avg_arr[i] << endl;
		}
	}

	else if (metric == "dept+gender") { //avg_pivot("dept+gender",dept_cnt)
		//2���� �迭 �����Ҵ�
		int** dept_gen_sum = new int* [count]; //���� �а��� ���� ���� �� �л����� ���� ���� �����ϴ� 2���� �迭
		int** dept_gen_cnt = new int* [count]; //���� �а��� ���� ���� �� �л����� ���� �����ϴ� 2���� �迭
		double** dept_gen_avg = new double* [count]; //���� �а��� ���� ���� �� �л��� ������ ����� �����ϴ� 2���� �迭
		for (int i = 0;i < count;i++) { 
			dept_gen_sum[i] = new int [2] {0};
			dept_gen_cnt[i] = new int[2] {0};
			dept_gen_avg[i] = new double[2] {0.0};
		}

		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) { //dept[i]�� �ش��ϴ� �а��� ���
					if (cur->data.gender == "F") { //�ش� �а��� ���л��� ���
						dept_gen_sum[i][0] += cur->data.age;
						dept_gen_cnt[i][0]++;
					} 
					else if (cur->data.gender == "M") { //�ش� �а��� ���л��� ���
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
				cout.precision(1); //�Ҽ��� ���ڸ����� �ݿø�
				if (j == 0) cout << "F\t" << dept_gen_avg[i][j] << endl;
				else cout << "M\t" << dept_gen_avg[i][j] << endl;
			}
		}
		//2���� �迭 �����Ҵ� ����
		for (int i = 0;i < count;i++) {
			delete[] dept_gen_sum[i];
			delete[] dept_gen_cnt[i];
			delete[] dept_gen_avg[i];
		}
		delete[] dept_gen_sum;
		delete[] dept_gen_cnt;
		delete[] dept_gen_avg;
	}
	//�迭 �����Ҵ� ����
	delete[] sum_arr;
	delete[] cnt_arr;
	delete[] avg_arr;
	return;
}

void list::max_pivot(string metric, int count) { //�ǹ� ��ȯ �� max �� ����ϴ� �Լ�
	if (count == 0) return;
	int* max_arr = new int[count] {0, }; //metric�� �������� pivot���� �� max ����� �����ϴ� 1���� �迭
	if (metric == "dept") { //max_pivot("dept", dept_cnt)
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) {
					if (cur->data.age > max_arr[i]) //�ִ밪���� ũ�� �ִ밪 ����
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
					if (cur->data.age > max_arr[i]) //�ִ밪���� ũ�� �ִ밪 ����
						max_arr[i] = cur->data.age;
				}
				cur = cur->next;
			}
			cout << gender[i] << "\t" << max_arr[i] << endl;
		}
	}
	else if (metric == "dept+gender") { //max_pivot("dept+gender",dept_cnt)
		//2���� �迭 �����Ҵ�
		int** dept_gen_max = new int* [count]; //���� �а��� ���� ���� �� �л��� ������ max�� �����ϴ� 2���� �迭
		for (int i = 0;i < count;i++) {
			dept_gen_max[i] = new int[2] {0, };
		}
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) { //dept[i]�� �ش��ϴ� �а��� ���
					if (cur->data.gender == "F") { //�ش� �а��� ���л��� ���
						if (cur->data.age > dept_gen_max[i][0]) //�ִ밪���� ū ��� �ִ밪 ����
							dept_gen_max[i][0] = cur->data.age;
					}
					else if (cur->data.gender == "M") { //�ش� �а��� ���л��� ���
						if (cur->data.age > dept_gen_max[i][1]) //�ִ밪���� ū ��� �ִ밪 ����
							dept_gen_max[i][1] = cur->data.age;
					}
				}
				cur = cur->next;
			}
			for (int j = 0;j < 2;j++) {
				if (dept_gen_max[i][j] == 0) continue; //�л� ���� 0�̸� ������� �ʴ´�.
				cout << dept[i] << "\t";
				if (j == 0) cout << "F\t" << dept_gen_max[i][j] << endl;
				else cout << "M\t" << dept_gen_max[i][j] << endl;
			}
		}
		//2���� �迭 �����Ҵ� ����
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
	int* min_arr = new int[count]; //metric�� �������� pivot���� �� min ����� �����ϴ� 1���� �迭
	for (int i = 0;i < count;i++) { //�迭 �ʱ�ȭ
		min_arr[i] = 1000;
	}
	if (metric == "dept") { //min_pivot("dept", dept_cnt)
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) {
					if (cur->data.age < min_arr[i]) //�ּҰ����� ������ �ּҰ� ����
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
					if (cur->data.age < min_arr[i]) //�ִ밪���� ũ�� �ִ밪 ����
						min_arr[i] = cur->data.age;
				}
				cur = cur->next;
			}
			cout << gender[i] << "\t" << min_arr[i] << endl;
		}
	}
	else if (metric == "dept+gender") { //min_pivot("dept+gender",dept_cnt)
		//2���� �迭 �����Ҵ�
		int** dept_gen_min = new int* [count]; //���� �а��� ���� ���� �� �л��� ������ min�� �����ϴ� 2���� �迭
		for (int i = 0;i < count;i++) {
			dept_gen_min[i] = new int[2];
		}
		for (int i = 0;i < count;i++) { //�迭 �ʱ�ȭ
			for (int j = 0;j < 2;j++) {
				dept_gen_min[i][j] = 100;
			}
		}
		for (int i = 0;i < count;i++) {
			node* cur = head;
			while (cur != NULL) {
				if (cur->data.dept == dept[i]) { //dept[i]�� �ش��ϴ� �а��� ���
					if (cur->data.gender == "F") { //�ش� �а��� ���л��� ���
						if (cur->data.age < dept_gen_min[i][0]) //�ּҰ����� ���� ��� �ּҰ� ����
							dept_gen_min[i][0] = cur->data.age;
					}
					else if (cur->data.gender == "M") { //�ش� �а��� ���л��� ���
						if (cur->data.age < dept_gen_min[i][1]) //�ּҰ����� ���� ��� �ּҰ� ����
							dept_gen_min[i][1] = cur->data.age;
					}
				}
				cur = cur->next;
			}
			for (int j = 0;j < 2;j++) {
				if (dept_gen_min[i][j] == 0) continue; //�л� ���� 0�̸� ������� �ʴ´�.
				cout << dept[i] << "\t";
				if (j == 0) cout << "F\t" << dept_gen_min[i][j] << endl;
				if (j == 1) cout << "M\t" << dept_gen_min[i][j] << endl;
			}
		}
		//2���� �迭 �����Ҵ� ����
		for (int i = 0;i < count;i++) {
			delete[] dept_gen_min[i];
		}
		delete[] dept_gen_min;
	}
	delete[] min_arr;
	return;
}