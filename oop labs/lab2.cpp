/*����� ����������� �����������, �����
����1-10 ������� �. �.
������������ �2
*/
#include <iostream>
#include <fstream>
using namespace std;

#define x 4
#define y 5

int nullrowdin(int **mat, int n, int m) {
	int q = 0;
	bool r = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0) {
				r = false;
			}
		}
		if (r) {
			q++;
		}
		r = true;
	}
	return q;
}

int maxnumdin(int **mat, int n, int m) {
	int max = -1;
	int sw = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] > max) {
				for (int d = 0; d < n; d++) {
					for (int f = 0; f < m; f++) {
						if (mat[d][f] == mat[i][j]) {
							sw++;
						}
					}
				}
				if (sw > 1) {
					max = mat[i][j];
				}
				sw = 0;
			}
		}
	}
	if (max == -1) {
		
		cout << "������ ����� �� ����������" << endl;
	}
	return max;
}

int nullrowstat(int mat[x][y]) {
	int q = 0;
	bool r = true;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mat[i][j] == 0) {
				r = false;
			}
		}
		if (r) {
			q++;
		}
		r = true;
	}
	return q;
}

int maxnumstat(int mat[x][y]) {
	int max = -1;
	int sw = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mat[i][j] > max) {
				for (int d = 0; d < x; d++) {
					for (int f = 0; f < y; f++) {
						if (mat[d][f] == mat[i][j]) {
							sw++;
						}
					}
				}
				if (sw > 1) {
					max = mat[i][j];
				}
				sw = 0;
			}
		}
	}
	if (max == -1) {

		cout << "������ ����� �� ����������" << endl;
	}
	return max;
}

void showliststat(int mat[x][y]) {
	cout << endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void showlistdin(int** mat, int n, int m) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	int n, m;
	int mat1[x][y] = { {7, 2, 3, 0, 5}, {6, 7, 8, 9, 10}, {213, 23, 2, 2, 4}, {0, 6, 2, 3, 1} };
	ifstream fin;
	fin.open("input.txt");
	fin >> n >> m;
	int** mat2 = new int* [n];
	for (int i = 0; i < n; i++) {
		mat2[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> mat2[i][j];
		}
	}
	fin.close();
	setlocale(LC_ALL, "Russian");
	char sol = ' ';
	int count = 1;
	double a;
	cout << "1 ���������� ���������� ����� �� ���������� �� ������ �������� �������� � ����������� �������" << endl;
	cout << "2 ���������� ���������� ����� �� ���������� �� ������ �������� �������� � ������������ �������" << endl;
	cout << "3 ���������� ������������ �� ����� ������������� � �������� ���p��� ����� ������ p��� � ����������� �������" << endl;
	cout << "4 ���������� ������������ �� ����� ������������� � �������� ���p��� ����� ������ p��� � ������������ �������" << endl;
	cout << "5 �������� ������������ ������" << endl;
	cout << "6 �������� ����������� ������" << endl;
	cout << "0 ���������� ������" << endl;
	while (count != 0) {
		cout << "�������� ��������:";
		cin >> count;
		switch (count) {
		case 1:
			cout << nullrowstat(mat1) << endl;;
			break;
		case 2:
			cout << nullrowdin(mat2, n, m) << endl;
			break;
		case 3:
			cout << maxnumstat(mat1) << endl;
			break;
		case 4:
			cout << maxnumdin(mat2, n, m) << endl;
			break;
		case 5:
			showliststat(mat1);
			break;
		case 6:
			showlistdin(mat2, n, m);
			break;
		case 0:
			sol = ' ';
			cout << "y / n �� ������������� ������ �����?" << endl;
			while (sol != 'y' && sol != 'n') {
				cin >> sol;
				switch (sol) {
				case 'y':
					for (int i = 0; i < n; i++) {
						delete[] mat2[i];
					}
					delete[] mat2;
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