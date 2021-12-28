/*����� ����������� �����������, �����
����1-10 ������ �. �.
������������ �1
*/
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

double f1(double a) {
	double z;
	z = 2 * pow(sin(3 * M_PI - 2 * a), 2) * pow(cos(5 * M_PI + 2 * a), 2);
	return z;
}

double f2(double a) {
	double z;
    z = (1. / 4.) - (1. / 4.) * sin((5. / 2.) * M_PI - 8 * a);
	return z;
}

int main() {
	setlocale(LC_ALL, "Russian");
	char sol = ' ';
    int count = 1;
	double a;
	cout << "1 ��������� 1 �������\n2 ��������� 2 �������\n3 ��������� ��� �������\n0 ���������� ������" << endl;
	while (count != 0) {
		cout << "�������� ��������:";
		cin >> count;
		switch (count) {
			case 1:
				cout << "������� ��������: ";
				cin >> a;
				if (cin.fail()) {
					while (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "������� ������������ ��������, ���������� �����" << endl;
						cout << "������� ��������: ";
						cin >> a;
					}
				}
				cout << "function 1 = ";
				cout << f1(a) << endl;
				break;
			case 2:
				cout << "������� ��������: ";
				cin >> a;
				if (cin.fail()) {
					while (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "������� ������������ ��������, ���������� �����" << endl;
						cout << "������� ��������: ";
						cin >> a;
					}
					
				}
				cout << "function 2 = ";
				cout << f2(a) << endl;
				break;
			case 3:
				cout << "������� ��������: ";
				cin >> a;
				if (cin.fail()) {
					while (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "������� ������������ ��������, ���������� �����" << endl;
						cout << "������� ��������: ";
						cin >> a;
					}
				}
				cout << "function 1 = ";
				cout << f1(a) << endl;
				cout << "function 2 = ";
				cout << f2(a) << endl;
				break;
			case 0:
				sol = ' ';
				cout << "y / n �� ������������� ������ �����?" << endl;
				while (sol != 'y' && sol != 'n') {
					cin >> sol;
					switch (sol) {
						case 'y':
							break;
						case 'n':
							count = 1;
							break;
						default:
							cout << "������� ������������ ��������, ���������� �����" << endl;
							break;
					}
				}
				break;
			default:
				cout << "������� ������������ ��������, ���������� �����" << endl;
				break;
		}
	}
	return 0;
}