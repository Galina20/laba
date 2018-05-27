#pragma once
#include "StackBase.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack1 : public StackBase<T>
{
private:
	T * data;
	int count, capacity; //count - последний элемент, capacity - длина стака
public:
	Stack1(int capacity)
	{
		this->capacity = capacity;
		this->count = -1;
		data = new T[capacity];
	}
	Stack1(const Stack1 &copy)
	{
		data = new T[copy.capacity];
		capacity = copy.capacity;
		count = copy.count;
		for (int i = 0; i <= count; ++i)
			data[i] = copy.data[i];
	}
	Stack1(Stack1 &&move)
	{
		data = move.data;
		capacity = move.capacity;
		count = move.count;
		move.data = nullptr;
	}
	~Stack1()
	{
		delete[] data;
	}

	Stack1 &operator=(const Stack1 &copy)
	{
		if (this == &copy) return *this;
		delete[] data;
		data = new T[copy.capacity];
		capacity = copy.capacity;
		count = copy.count;
		for (int i = 0; i <= count; ++i)
			data[i] = copy.data[i];
	}
	Stack1 &operator=(Stack1 &&move)
	{
		if (this == &move) return *this;
		delete[] data;
		data = move.data;
		count = move.count;
		capacity = move.capacity;
		move.data = nullptr;
	}
	T &operator[](int index)
	{
		if (index < 0 || index > count)
			throw out_of_range("index was outside the array boundaries");
		return data[index];
	}
	friend ostream& operator<<(ostream& stream, const Stack1& data)
	{
		for (int i = 0; i <= data.count; ++i)
			cout << data.data[i] << " ";
		return stream;
	}

	int GetCapacity()
	{
		return capacity;
	}
	int GetSize() override
	{
		return count + 1;
	}
	T Pop() override
	{
		if (count == -1) throw out_of_range("stack is empty");
		return data[count--];
	}
	void Push(const T &element) override
	{
		if (count + 1 >= capacity) throw out_of_range("stack is full");
		data[++count] = element;
	}
	T Peek() override
	{
		if (count == -1) throw out_of_range("stack is empty");
		return data[count];
	}
};