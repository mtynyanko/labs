/*Южный федеральный университет, ИКТИБ
КТбо1-10 Тыянко М. А.
Лабораторная работа №4
*/

#include <iostream>
#include <fstream>
using namespace std;

struct person {
	int status;
	string name;
	int h;
	int m;
	int s;
	int insec;
	int alltime = 0;
	bool check = false;
	bool first = true;
	bool on = false;
};
person* persons;

int aritmean(int n) {
	int sum = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (persons[i].first && persons[i].check && !persons[i].on) {
			sum += persons[i].alltime;
			m++;
		}
		
	}
	if (m != 0) {
		sum = sum / m;
	}
	else {
		sum = 0;
	}
	return sum;
}

int allsec(int a, int b, int c) {
	int sec = c + (60 * b) + (600 * a);
	return sec;
}


void searchtime(int n) {
	int f = -1;
	for (int i = 0; i < n; i++) {
		if (persons[i].first && persons[i].status == 1) {
			for (int j = i + 1; j < n; j++) {
				if (persons[i].name == persons[j].name) {
					persons[j].first = false;
				}
			}
			for (int j = 0; j < n; j++) {
				if (persons[j].status == -1 && persons[i].name == persons[j].name && !persons[j].check) {
					persons[i].alltime += (persons[j].insec - persons[i].insec);
					persons[j].check = true;
					persons[i].check = true;
					break;
				}
			}
		}
		else if (!persons[i].first && persons[i].status == 1) {
			for (int j = 0; j < n; j++) {
				if (persons[i].name == persons[j].name && persons[j].first) {
					f = j;
				}
			}
			if (f != -1) {
				for (int j = 0; j < n; j++) {
					if (persons[j].status == -1 && persons[i].name == persons[j].name && !persons[j].check) {
						persons[f].alltime += (persons[j].insec - persons[i].insec);
						persons[j].check = true;
						persons[i].check = true;
						break;
					}
				}
			}
			else if (f == -1) {
				persons[i].on = true;
			}
		}
		else if (persons[i].first && persons[i].status == -1) {
			persons[i].alltime = persons[i].insec;
			persons[i].check = true;
		}
		f = -1;
	}
}

void read(int *n) {
	ifstream fin;
	fin.open("input.txt");
	fin >> *n;
	persons = new person[*n];
	for (int i = 0; i < *n; i++) {
		fin >> persons[i].name;
		fin >> persons[i].h;
		fin.ignore();
		fin >> persons[i].m;
		fin.ignore();
		fin >> persons[i].s;
		fin >> persons[i].status;
	}
	fin.close();
}

void write(int d, int *arm, int n) {
	ofstream fout;
	fout.open("output.txt");
	fout << d << endl;
	for (int i = 0; i < n; i++) {
		if (persons[i].alltime < *arm && persons[i].first && persons[i].check && !persons[i].on) {
			fout << persons[i].name << " ";
			fout << persons[i].h << ":";
			fout << persons[i].m << ":";
			fout << persons[i].s << " ";
			fout << persons[i].status << endl;
		}
	}
	fout.close();
}

int main() {
	int arm;
	int n, d = 0;
	read(&n);
	for (int i = 0; i < n; i++) {
		persons[i].insec = allsec(persons[i].h, persons[i].m, persons[i].s);
	}
	
	searchtime(n);
	arm = aritmean(n);

	for (int i = 0; i < n; i++) {
		if (persons[i].alltime < arm && persons[i].first && persons[i].check && !persons[i].on) {
			d++;
		}
	}
	write(d, &arm, n);
	
	delete[] persons;
	return 0;
}