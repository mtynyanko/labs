/*Южный федеральный университет, ИКТИБ
КТбо1-10 Тыянко М. А.
Лабораторная работа №3
*/

#include "Matrixes.h"
#include <iostream>
#include <fstream>

using namespace std;

int** mat_a;
int** mat_b;
int** mat_c;

void read2m(int* n1, int* m1, int* n2, int* m2) {
	ifstream fin;
	fin.open("input.txt");
	fin >> *n1 >> *m1 >> *n2 >> *m2;
	mat_a = new int* [*n1];
	mat_b = new int* [*n2];
	for (int i = 0; i < *n1; i++) {
		mat_a[i] = new int[*m1];
		for (int j = 0; j < *m1; j++) {
			fin >> mat_a[i][j];
		}
	}
	for (int i = 0; i < *n2; i++) {
		mat_b[i] = new int[*m2];
		for (int j = 0; j < *m2; j++) {
			fin >> mat_b[i][j];
		}
	}
	fin.close();
}

void write(int n, int m, int** mat) {
	ofstream fout;
	fout.open("output.txt");
	fout << n << " " << m << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fout << mat[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

void clean(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

void choice(int n1, int m1, int n2, int m2, int n, int m) {
	string tt;
	if (n1 == n2) {
		cout << "a or v" << endl;
		cin >> tt;
		if (tt == "a") {
			task_a(n1, m1, n2, m2, n, m, mat_a, mat_b, mat_c);
		}
		else if (tt == "v") {
			task_v(n1, m1, n2, m2, n, m, mat_a, mat_b, mat_c);
		}
	}
	else if (m1 == m2) {
		cout << "b or g" << endl;
		cin >> tt;
		if (tt == "b") {
			task_b(n1, m1, n2, m2, n, m, mat_a, mat_b, mat_c);
		}
		else if (tt == "g") {
			task_g(n1, m1, n2, m2, n, m, mat_a, mat_b, mat_c);
		}
	}
}

int main() {
	int n1 = 0, m1 = 0, n2 = 0, m2 = 0;
	
	read2m(&n1, &m1, &n2, &m2);
	int n = n1 + n2;
	int m = m1 + m2;
	if (n1 == n2) {
		n = n1;
		m = m1 + m2;
	}
	else if (m1 == m2) {
		m = m1;
		n = n1 + n2;
	}
	else {
		cout << "error 999" << endl;
		return 0;
	}
	mat_c = new int* [n];
	for (int i = 0; i < n; i++) {
		mat_c[i] = new int[m];
	}
	choice(n1, m1, n2, m2, n, m);
	write(n, m, mat_c);
	clean(mat_a, n1);
	clean(mat_b, n2);
	clean(mat_c, n);
	return 0;
}