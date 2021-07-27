#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // для assert()
#include <iostream>
class ArrayInt
{
private:
int m_length;
int *m_data;
public:
ArrayInt(): m_length(0), m_data(nullptr)
{ }
ArrayInt(int length):
m_length(length)
{
assert(length >= 0);
if (length > 0)
m_data = new int[length];
else
m_data = nullptr;
}
~ArrayInt()
{
delete[] m_data;
}
void erase();
int getLength();
int& operator[](int index);
void resize(int newLength);
void insertBefore(int value, int index);
void push_back(int value);
int  pop_back();
int  pop_front();
void print_el(int begin,int end);  //  на будущее печать диапазона элементов
void print_all();// printing all elements
void sort_all(bool);
};
#endif
