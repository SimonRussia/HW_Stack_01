#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
//Декларируем необходимые методы
    Stack(); 			// Конструктор класса без параметров (по умолчанию 10)
    Stack(size_t s); 		// Параметрический конструктор класса.
    void StackExpand(); 	//Метод для расширения памяти массива.
    size_t count() const; 	//Константный метод (Чтобы не изменить значение), возвращает значение счетчика.
    void push(T const &); 	//Метод принимающий константную ссылку на значение.
    T pop(); 			//Метод удаления последней переменной.
    ~Stack();
private:
    T* array_; 			//Указатель на массив.
    size_t array_size_;
    size_t count_;
};


//ВНЕШНЯЯ РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА STACK

//Конструктор Stack без параметров.
template <typename T>
Stack <T> :: Stack() : array_size_(10) {
    array_ = new T[array_size_]; 	//Определяем указатель выделенной для массива памятью.
    count_ = -1; 			//Устанавливаем значение счетчика.
}

//Конструктор Stack параметрический.
template <typename T>
Stack <T> :: Stack(size_t s) : array_size_(s) {
    array_ = new T[array_size_]; 	//Определяем указатель выделенной для массива памятью.
    count_ = -1; 			//Устанавливаем значение счетчика.
}

//Деструктор Stack.
template <typename T>
Stack <T> :: ~Stack() {
    delete[] array_; 			//Освобождаем выделенную память.
}

//Функция push.
template <typename T>
void Stack <T> :: push(T const &val) {
	array_[++count_] = val; 	//Добавляем значение в массив по ссылке.
	if(count_ == (array_size_-1)) StackExpand(); 	//Функция для проверки заполнения и перевыделения памяти.
}

//Функция StackExpand.
template <typename T>
void Stack <T> :: StackExpand() {
	T* array_exp_ = new T[array_size_*2]; 		//Определяем указатель на новый массив с увеличенной памятью.
	for(int i = 0; i < array_size_; i++) { 		//В цикле переносим значения из старого в новый массив.
		array_exp_[i] = array_[i];
	}
	array_size_ *= 2;
	delete[] array_; 		//Освобождаем память старого массива
	array_ = array_exp_; 		//Переопределяем указатель.
}

//Функцию pop.
template <typename T>
T Stack <T> :: pop() {
	if(count_ == -1) throw runtime_error("ERROR: Stack Empty!"); 	//Контролируем счетчик (чтобы не выйти за границы массива), бросаем исключение.
	return array_[count_--];
}


//MAIN

int main() {
	try {
		cout << endl << "***** INT - Stack *****" << endl;
		Stack<int> A(3); 	//Создаем объект класса Stack типа int, размера 3.
		A.push(3); 		//Добавляем элементы...
		A.push(5);
		A.push(7);
		A.push(9);
		A.push(2);
		A.push(4);
		A.push(6);
		A.push(8);

		for(int i = 0; i < 8; i++) {	 //Удаляем элементы.
			cout << A.pop() << endl;
		}
		cout << endl << endl;

		cout << "**** CHAR - Stack *****" << endl;
		Stack<char> B(2); 	//Создаем объект класса Stack типа int, размера 2.
		B.push('3'); 		//Добавляем элементы...
		B.push('3');
		B.push('-');
		B.push('8');
		B.push('U');
		B.push('I');

		for(int i = 0; i < 6; i++) { 	//Удаляем элементы.
			cout << B.pop();
		}
		cout << endl << endl;

	} catch(const exception& e) { 	//Ловим исключения.
		cout << e.what() << endl;
	}
}
