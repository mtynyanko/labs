/*Южный федеральный университет, ИКТИБ
КТбо1-10 Тыянко М. А.
Лабораторная №1
*/
#include <iostream>
#include <fstream>

using namespace std;

int mplus(int **matrix, int u, int t) {
	int sum = 0;
	for (int i = 0; i <= u; i++) {
		for (int j = 0; j <= t; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

int main() {
	int n, m;
	ifstream fin;
	fin.open("input.txt");
	fin >> n >> m;
	int** matrix2 = new int* [n];
	int** matrix1 = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix1[i] = new int[m];
		matrix2[i] = new int[m];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> matrix1[i][j];
		}
	}
	fin.close();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix2[i][j] = mplus(matrix1, i, j);
		}
	}
	ofstream fout;
	fout.open("output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fout << matrix2[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
	for (int i = 0; i < n; i++) {
		delete[] matrix1[i]; 
		delete[] matrix2[i];
	}
	delete[] matrix1;
	delete[] matrix2;
	return 0;
}