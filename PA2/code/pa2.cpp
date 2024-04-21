#include <iostream>
#include <string>
#include <cmath>
#include "get_string.cpp"
#include "student.hpp"
#include "node.hpp"
#include "list.hpp"

using namespace std;

void show_menu() {
	cout << "----------MENU----------" << endl;
	cout << "1. Add a student" << endl;
	cout << "2. Delete a student" << endl;
	cout << "3. Print the student's list" << endl;
	cout << "4. Pivot Table" << endl;
	cout << "5. Exit" << endl;
	cout << "------------------------" << endl;
	cout << "Selection: ";
}

int main() {
	string choice = "0";
	list students;
	students.count = 0;
	students.dept_cnt = 0;
	students.head = NULL;
	
	while (1) {
		show_menu();
		choice = get_string();
		if (choice == "1") {
			students.add_student();
		}
		else if (choice == "2") {
			students.del_student();
		}
		else if (choice == "3") {
			students.print_list();
		}
		else if (choice == "4") {
			students.pivot_list();
		}
		else if (choice == "5") {
			return 0;
		}
		else {
			cout << "Invalid input! Try again." << endl;
			continue;
		}
	}
}

