#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
//Декларируем необходимые методы
    Stack(); 			// Конструктор класса без параметров (по умолчанию 10)
    Stack(size_t s); 		// Параметрический конструктор класса.
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
Stack <T> :: Stack() {
    array_size_ = 10; 			//Задаем размер Stack по  умолчанию.
    array_ = new T[array_size_]; 	//Определяем указатель выделенной для массива памятью.
    count_ = 0; 			//Устанавливаем значение счетчика.
}

//Конструктор Stack параметрический.
template <typename T>
Stack <T> :: Stack(size_t s) : array_size_(s) {
    array_ = new T[array_size_]; 		//Определяем указатель выделенной для массива памятью.
    count_ = 0; 				//Устанавливаем значение счетчика.
}

//Деструктор Stack.
template <typename T>
Stack <T> :: ~Stack() {
    delete[] array_; 				//Освобождаем выделенную память.
}

//Функция push.
template <typename T>
void Stack <T> :: push(T const &val) {
	if(count_ == array_size_) {
		T* array_exp_ = new T[array_size_*2]; 		//Определяем указатель на новый массив с увеличенной памятью.
		for(int i = 0; i < array_size_; i++) { 		//В цикле переносим значения из старого в новый массив.
			array_exp_[i] = array_[i];
		}
		array_size_ *= 2;
		delete[] array_; 		//Освобождаем память старого массива
		array_ = array_exp_; 		//Переопределяем указатель.

		array_[count_++] = val;
	} else {
		array_[count_++] = val; 	//Добавляем значение в массив по ссылке.
	}
}

//Функцию pop.
template <typename T>
T Stack <T> :: pop() {
	if(count_ == 0) throw runtime_error("ERROR: Stack Empty!"); 	//Контролируем счетчик (чтобы не выйти за границы массива), бросаем исключение.
	return array_[--count_];
}

//Функцию count.
template <typename T>
size_t Stack <T> :: count() const {
	return count_;
}
