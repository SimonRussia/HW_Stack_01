#include <iostream>
#include "stack.hpp"
using namespace std;

int main() {
	try {
		cout << endl << "***** INT - Stack *****" << endl;
		Stack<int> A; //Создаем объект класса Stack типа int.
		A.push(3); //Добавляем элементы...
		A.push(5);
		A.push(7);
		A.push(9);
		A.push(2);
		A.push(4);
		A.push(6);
		A.push(8);

		for(int i = 0; i < (A.count()+i); i++) { //Удаляем элементы.
			cout << A.pop() << endl;
		}
		cout << endl << endl;

		cout << "**** CHAR - Stack *****" << endl;
		Stack<char> B(2); //Создаем объект класса Stack типа int, размера 2.
		B.push('3'); //Добавляем элементы...
		B.push('3');
		B.push('-');
		B.push('8');
		B.push('U');
		B.push('I');

		for(int i = 0; i < (B.count()+i); i++) { //Удаляем элементы.
			cout << B.pop();
		}
		cout << endl << endl;

	} catch(const exception& e) { //Ловим исключения.
		cout << e.what() << endl;
	}
}