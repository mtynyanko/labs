/*����� ����������� �����������, �����
����1-10 ������� �. �.
������������ �4
*/

#include <iostream>
#include <stack>
#include <fstream>
#include <iterator>
using namespace std;


class StackTrains {
	public:
		void pushtrain(int a) {
			train.push(a);
		}

		void showtop() {
			cout << train.top() << endl;
		}

		void takeouttrain() {
			while (!train.empty()) {
				cout << train.top() << " ";
				train.pop();
			}
			cout << endl;
		}
		
	private:
		stack <int> train;
		int a;
};

StackTrains pass, gruz;

void readconsle() {
	
	int n;
	string traintype;
	int wagon;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> traintype >> wagon;
		if (traintype == "pass") {
			pass.pushtrain(wagon);
		}
		else if (traintype == "gruz"){
			gruz.pushtrain(wagon);
		}
		else {
			cout << "����������� ��� ������" << endl;
		}
	}
}

void readfile() {
	
	ifstream fin;
	int n;
	fin.open("input.txt");
	string traintype;
	int wagon;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> traintype >> wagon;
		if (traintype == "pass") {
			pass.pushtrain(wagon);
		}
		else if (traintype == "gruz") {
			gruz.pushtrain(wagon);
		}
		else {
			cout << "����������� ��� ������" << endl;
		}
	}
	fin.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	string sol = " ";
	int count = 1;
	cout << "1 ��������� ������ � �������\n2 ��������� ������ �� �����\n3 �������� ������� �������� �����\n4 �������� ������� ������������ �����\n5 �������� � ������� ��� �������� ������\n6 �������� � ������� ��� ������������ ������\n0 ���������� ������" << endl;
	while (count != 0) {
		cout << "�������� ��������:";
		cin >> count;
		switch (count) {
		case 1:
			readconsle();
			break;
		case 2:
			readfile();
			break;
		case 3:
			gruz.showtop();
			break;
		case 4:
			pass.showtop();
			break;
		case 5:
			gruz.takeouttrain();
			break;
		case 6:
			pass.takeouttrain();
			break;
		case 0:
			sol = " ";
			cout << "[y / n] �� ������������� ������ �����?" << endl;
			while (sol[0] != 'y' && sol[0] != 'n') {
				cin >> sol;
				switch (sol[0]) {
				case 'y':
					break;
				case 'n':
					count = 1;
					break;
				default:
					cout << "������� ������������ ��������, ���������� �����" << endl;
					cin.clear();
					cin.ignore();
					break;
				}
			}
			break;
		default:
			cout << "������� ������������ ��������, ���������� �����" << endl;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	return 0;
}