#pragma once
#include "StackBase.h"
#include "UnidirCyclicList.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack2 : public StackBase<T>
{
private:
	UnidirCyclicList<T> *data;
	int count, sizemax;
public:
	Stack2(int size)
	{
		sizemax = size;
		this->count = 0;
		data = new UnidirCyclicList<T>();
	}
	Stack2(const Stack2 &copy)
	{
		data = new UnidirCyclicList<T>();
		count = copy.count;
		for (int i = 0; i < count; ++i)
			data->AddBack(copy.data->ElementAt(count - i));
	}
	Stack2(Stack2 &&move)
	{
		data = move.data;
		count = move.count;
		move.data = nullptr;
	}
	~Stack2()
	{
		delete data;
	}

	Stack2 &operator=(const Stack2 &copy)
	{
		if (this == &copy) return *this;
		delete data;
		data = new UnidirCyclicList<T>();
		count = copy.count;
		for (int i = 0; i < count; ++i)
			data->AddBack(copy.data->ElementAt(count - i));
	}
	Stack2 &operator=(Stack2 &&move)
	{
		if (this == &move) return *this;
		delete data;
		data = move.data;
		count = move.count;
		move.data = nullptr;
	}
	T &operator[](int index)
	{
		if (index < 0 || index > count)
			throw out_of_range("index was outside the array boundaries");
		return data->ElementAt(index);
	}
	friend ostream& operator<<(ostream& stream, const Stack2& data)
	{
		for (int i = 0; i < data.count; ++i)
			cout << data.data->ElementAt(i) << " ";
		return stream;
	}

	int GetSize() override
	{
		return count;
	}
	T Pop() override
	{
		if (count == 0)
		{
			throw out_of_range("stack is empty");
		}
		T ret = data->ElementAt(--count);
		data->RemoveBack();
		return ret;
	}
	void Push(const T &element) override
	{
		if (sizemax == count) throw out_of_range("stack is full");
		data->AddFront(element);
		++count;
	}
	T Peek() override
	{
		if (count == 0) throw out_of_range("stack is empty");
		return data->ElementAt(count - 1);
	}
};