#pragma once
#include <iostream>
using namespace std;


void task_a(int n1, int m1, int n2, int m2, int n, int m, int** mat_a, int** mat_b, int** mat_c){
	int p = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m1; j++) {
			mat_c[i][p] = mat_a[i][j];
			p++;
		}
		for (int j = 0; j < m2; j++) {
			mat_c[i][p] = mat_b[i][j];
			p++;
		}
		p = 0;
	}
}

void task_b(int n1, int m1, int n2, int m2, int n, int m, int** mat_a, int** mat_b, int** mat_c) {
	int p = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n1; i++) {
			mat_c[p][j] = mat_a[i][j];
			p++;
		}
		for (int i = 0; i < n2; i++) {
			mat_c[p][j] = mat_b[i][j];
			p++;
		}
		p = 0;
	}
}

void task_v(int n1, int m1, int n2, int m2, int n, int m, int** mat_a, int** mat_b, int** mat_c) {
	bool sw = true;
	int a = 0;
	int b = 0;
	int ma = m1;
	int mb = m2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sw && ma > 0) {
				mat_c[i][j] = mat_a[i][a];
				a++;
				sw = false;
				ma--;
			}
			else if (!sw && mb > 0) {
				mat_c[i][j] = mat_b[i][b];
				b++;
				sw = true;
				mb--;
			}
			else if (ma > 0) {
				mat_c[i][j] = mat_a[i][a];
				a++;
			}
			else {
				mat_c[i][j] = mat_b[i][b];
				b++;
			}
		}
		ma = m1;
		mb = m2;
		a = 0;
		b = 0;
		sw = true;
	}
}

void task_g(int n1, int m1, int n2, int m2, int n, int m, int** mat_a, int** mat_b, int** mat_c) {
	bool sw = true;
	int a = 0;
	int b = 0;
	int na = n1;
	int nb = n2;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (sw && na > 0) {
				mat_c[i][j] = mat_a[a][j];
				a++;
				sw = false;
				na--;
			}
			else if (!sw && nb > 0) {
				mat_c[i][j] = mat_b[b][j];
				b++;
				sw = true;
				nb--;
			}
			else if (na > 0) {
				mat_c[i][j] = mat_a[a][j];
				a++;
			}
			else {
				mat_c[i][j] = mat_b[b][j];
				b++;
			}
		}
		na = n1;
		nb = n2;
		a = 0;
		b = 0;
		sw = true;
	}
}