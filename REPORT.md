## Homework I (Stack #1)
Данная домашняя работа посвящена изучению шаблонов и работой с классами.

## Tasks
- [x] Реализовать шаблонный класс `stack`, со следующим интерфейсом:

## Tutorial

```ShellSession
template <typename T>
class stack
{
public:
    stack();
    size_t count() const;
    void push(T const &);
    T pop();
private:
    T * array_;
    size_t array_size_;
    size_t count_;
};
```
## Terminal message
```ShellSession
***** INT - Stack *****
8
6
4
2
9
7
5
3


**** CHAR - Stack *****
IU8-33
```
