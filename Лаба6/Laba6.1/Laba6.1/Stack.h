#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
public:
	Stack(int capacity)
	{
		this->capacity = capacity;
		this->count = -1;
		data = new T[capacity];
	}
	Stack(const Stack &copy)
	{
		data = new T[copy.capacity];
		capacity = copy.capacity;
		count = copy.count;
		for (int i = 0; i <= count; ++i)
			data[i] = copy.data[i];
	}
	Stack(Stack &&move)
	{
		data = move.data;
		capacity = move.capacity;
		count = move.count;
		move.data = nullptr;
	}
	~Stack()
	{
		delete[] data;
	}

	Stack &operator=(const Stack &copy)
	{
		if (this == &copy) return *this;
		delete[] data;
		data = new T[copy.capacity];
		capacity = copy.capacity;
		count = copy.count;
		for (int i = 0; i <= count; ++i)
			data[i] = copy.data[i];
		return *this;
	}
	Stack &operator=(Stack &&move)
	{
		if (this == &move) return *this;
		delete[] data;
		data = move.data;
		count = move.count;
		capacity = move.capacity;
		move.data = nullptr;
		return *this;
	}
	T &operator[](int index)
	{
		if (index < 0 || index > count)
			throw out_of_range("index was outside the array boundaries");
		return data[index];
	}
	friend ostream& operator<<(ostream& stream, const Stack& data)
	{
		for (int i = 0; i <= data.count; ++i)
			cout << data.data[i] << " ";
		return stream;
	}

	int GetSize()
	{
		return count + 1;
	}
	int GetCapacity()
	{
		return capacity;
	}
	T Pop()
	{
		if (count == -1) throw out_of_range("stack is empty");
		return data[count--];
	}
	void Push(T value)
	{
		if (count + 1 >= capacity) throw out_of_range("stack is full");
		data[++count] = value;
	}
	T Peek()
	{
		if (count == -1) throw out_of_range("stack is empty");
		return data[count];
	}

private:
	T * data;
	int count, capacity; //count - последний элемент, capacity - длина стака
};
