/*Южный федеральный университет, ИКТИБ
КТбо1-6 Тыянко М. А.
Лабораторная работа №1
Структуры и аолгоритмы обработки данных
задание 5: Циклический односвязный список с указателем на последний узел. Дополнительные
операции: a) поменять местами первый и второй (если он есть) узлы (требуется
поменять именно узлы, а не их значения); б) удалить узел с указанным порядковым
номером.
*/
#include <iostream>
using namespace std;


typedef struct Item {
	Item* next;
	int data;
} Item;

typedef Item* List;
List p;
List tail;
List head;

void initlist() {
	List tail = NULL;
}

void inhead(int a) {

	if (tail == NULL) {
		tail = new Item;
		tail->data = a;
		tail->next = tail;
	}
	else {
		p = new Item;
		p->data = a;
		p->next = tail->next;
		tail->next = p;
	}
}

void intail(int a) {
	if (tail == NULL) {
		tail = new Item;
		tail->data = a;
		tail->next = tail;
	}
	else {
		p = new Item;
		p->data = a;
		p->next = tail->next;
		tail->next = p;
		tail = p;
	}
}


void showlist() {
	if (tail == NULL) {
		cout << "список пуст!" << endl;
	}
	else {
		p = tail->next;
		cout << p->data << " ";
		p = p->next;
		while (p != tail->next) {
			cout << p->data << " ";
			p = p->next;
		}
	}
}

void swap() {
	List a = tail->next;
	List b = a->next;
	tail->next = b;
	a->next = b->next;
	b->next = a;
}


void delhead() {
	head = tail->next;
	p = tail->next;
	if (head->next == head) {
		delete tail;
		tail = NULL;
	}
	else {
		tail->next = p->next;
		delete p;
		p = NULL;
	}
}

void deltail() {
	head = tail->next;
	p = tail->next;
	if (head->next == head) {
		delete tail;
		tail = NULL;
	}
	else {
		while (p->next != tail) {
			p = p->next;
		}
		List q = p->next;
		p->next = tail->next;
		tail = p;
		delete q;
		q = NULL;
	}
}

void del(int a) {
	head = tail->next;
	if (a > 1) {
		p = tail->next;
		for (int i = 1; i < a - 1; i++) {
			p = p->next;
		}
		if (p->next == tail) {
			deltail();
		}
		else {
			if (head->next == head) {
				delete tail;
				tail = NULL;
			}
			else {
				List q = p;
				p = p->next;
				q->next = p->next;
				delete p;
			}
		}
	}
	else {
		delhead();
	}
}


int dellist() {
	if (tail == NULL) {
		printf("список пуст");
	}
	else {
		head = tail->next;
		if (head->next == head) {
			delhead();
			tail = NULL;
		}
		else {
			delhead();
			dellist();
			return 0;
		}
	}

}

void printmenu() {
	cout << "действия со списком" << endl;
	cout << "1 - инициализация пустого списка" << endl;
	cout << "2 - уничтожение списка с освобождением памяти" << endl;
	cout << "3 - добавление узла в голову списка" << endl;
	cout << "4 - добавление узла в хвост списка" << endl;
	cout << "5 - поменять местами первый и второй узлы" << endl;
	cout << "6 - удаление узла из головы списка" << endl;
	cout << "7 - удаление узла из хвоста списка" << endl;
	cout << "8 - удалить узел с указанным порядковым номером" << endl;
	cout << "9 - выдача теущего списка на экран" << endl;
	cout << "0 - завершение работы" << endl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int mod = 10;
	int a;
	printmenu();
	while (mod != 0) {
		cin >> mod;
		if (mod == 1) {
			initlist();
		}
		else if (mod == 2) {
			dellist();
		}
		else if (mod == 3) {
			cout << "введите число" << endl;
			cin >> a;
			inhead(a);
		}
		else if (mod == 4) {
			cout << "введите число" << endl;
			cin >> a;
			intail(a);
		}
		else if (mod == 5) {
			swap();
		}
		else if (mod == 6) {
			delhead();
		}
		else if (mod == 7) {
			deltail();
		}
		else if (mod == 8) {
			cout << "введите номер узла" << endl;
			cin >> a;
			del(a);
		}
		else if (mod == 9) {
			showlist();
		}
		else if (mod == 0) {

		}
		else {
			cout << "такой функции не сущетвует" << endl;
		}
	}
	return 0;
}

