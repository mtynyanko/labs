/*Южный федеральный университет, ИКТИБ
КТбо1-10 Тынянко М. А.
Лабораторная №3
*/
#include <iostream>
#include <string>
using namespace std;

#define size 10

struct STUDENT {
	string sname;
	int group;
	int marks[5];
	float as;
} students[size]; 

bool sw = false;

void swap(STUDENT* a, STUDENT* b) {
	STUDENT t = *a;
	*a = *b;
	*b = t;
}

float average_score(int marks[5]) {
	float avs = 0;
	for (int i = 0; i < 5; i++) {
		avs += marks[i];
	}
	return avs /= 5;
}

void sort() {
	int n = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (students[j].group > students[j + 1].group) {
				n++;
				swap(students[j], students[j + 1]);
			}
		}
	}
}

void read() {
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < size; i++) {
		cin >> students[i].sname;
		cin >> students[i].group;
		for (int j = 0; j < 5; j++) {
			cin >> students[i].marks[j];
		}
	}
	sw = true;
}

void show_list() {
	if (sw) {
		cout << endl;
		for (int i = 0; i < size; i++) {
			cout << students[i].sname << " " << students[i].group << " ";
			for (int j = 0; j < 5; j++) {
				cout << students[i].marks[j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "таблица пуста" << endl;
	}
}

void show_list_highmark() {
	if (sw) {
		bool mod = false;
		cout << endl;
		for (int i = 0; i < size; i++) {
			if (average_score(students[i].marks) > 4) {
				mod = true;
				cout << students[i].sname << " " << students[i].group << " ";
				for (int j = 0; j < 5; j++) {
					cout << students[i].marks[j] << " ";
				}
				cout << endl;
			}
		}
		if (!mod) {
			cout << "нет таких студентов, удволетворяющих запрос" << endl;
		}
	}
	else {
		cout << "таблица пуста" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	string sol = " ";
	int count = 1;
	cout << "1 загрузить таблицу\n2 показать всю упорядоченную таблицу\n3 показать всех студентов, включенных в массив, если средний балл студента больше 4.0\n0 завершение работы" << endl;
	while (count != 0) {
		cout << "Выберите действие:";
		cin >> count;
		switch (count) {
		case 1:
			read();
			break;
		case 2:
			show_list();
			break;
		case 3:
			show_list_highmark();
			break;
		case 0:
			sol = " ";
			cout << "y / n Вы действительно хотите выйти?" << endl;
			while (sol[0] != 'y' && sol[0] != 'n') {
				cin >> sol;
				switch (sol[0]) {
				case 'y':
					break;
				case 'n':
					count = 1;
					break;
				default:
					cout << "Введены некорректные значения, попробуйте снова" << endl;
					cin.clear();
					cin.ignore();
					break;
				}
			}
			break;
		default:
			cout << "Введены некорректные значения, попробуйте снова" << endl;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	return 0;
}

