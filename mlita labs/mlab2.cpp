/*Южный федеральный университет, ИКТИБ
КТбо1-10 Тыянко М. А.
Лабораторная работа №2
*/

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

double** eucl;

void readbin(int *n, int *k, double *r) {
	ifstream fin;
	fin.open("input.bin", ios::binary);
	fin.read((char*)n, 4);
	fin.read((char*)k, 2);
	fin.read((char*)r, 8);
	eucl = new double* [sizeof(double) * *n];
	for (int i = 0; i < *n; i++) {
		eucl[i] = new double[*k];
		for (int j = 0; j < *k; j++) {
			fin.read((char*)&eucl[i][j], 8);
		}
	}
	fin.close();
}

void writebin(int *size, int *k, double **arr) {
	ofstream fout;
	fout.open("output.bin", ios::binary);
	fout.write((char*)size, 4);
	fout.write((char*)k, 2); 
	cout << *size << " " << *k << endl;
	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *k; j++) {
			cout << arr[i][j] << " ";
			fout.write((char*)&arr[i][j], 8);
		}
		cout << endl;
	}
	fout.close();
}
	
int counteu(int n, int k, double **arr_2, double r, int *in) {
	int size = 0;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum = pow(eucl[i][0] - eucl[i][1], 2);
		sum = sqrt(sum);
		if (sum >= r) {
			in[size] = i;
			size++;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < k; j++) {
			arr_2[i][j] = eucl[in[i]][j];
		}
	}
	return size;
}


int main() {
	int k = 0, n = 0, size;
	double r;
	readbin(&n, &k, &r);
	int* in = new int[n];
	double** answ = new double* [n];
	for (int i = 0; i < n; i++) {
		answ[i] = new double[k];
	}
	size = counteu(n, k, answ, r, in);
	writebin(&size, &k, answ);
	for (int i = 0; i < n; i++) {
		delete[] eucl[i];
		delete[] answ[i];
	}
	delete[] eucl;
	delete[] answ;
	delete[] in;
	return 0;
}



