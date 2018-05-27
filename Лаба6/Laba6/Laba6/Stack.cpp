#include "Stack.h"

Stack::Stack(int capacity)
{
	this->capacity = capacity;
	this->count = -1;
	data = new int[capacity];
}

Stack::Stack(const Stack &copy)
{
	data = new int[copy.capacity];
	capacity = copy.capacity;
	count = copy.count;
	for (int i = 0; i <= count; ++i)
		data[i] = copy.data[i];
}

Stack::Stack(Stack &&move)
{
	data = move.data;
	capacity = move.capacity;
	count = move.count;
	move.data = nullptr;
}

Stack::~Stack()
{
	delete[] data;
}


Stack &Stack::operator=(const Stack &copy)
{
	if (this == &copy) return *this;
	delete[] data;
	data = new int[copy.capacity];
	capacity = copy.capacity;
	count = copy.count;
	for (int i = 0; i <= count; ++i)
		data[i] = copy.data[i];
	return *this;
}

Stack &Stack::operator=(Stack &&move)
{
	if (this == &move) return *this;
	delete[] data;
	data = move.data;
	count = move.count;
	capacity = move.capacity;
	move.data = nullptr;
	return *this;
}

ostream &operator<<(ostream &stream, const Stack &value)
{
	for (int i = 0; i <= value.count; ++i)
		cout << value.data[i] << " ";
	return stream;
}

int &Stack::operator[](int index)
{
	if (index < 0 || index > count)
		throw out_of_range("index was outside the array boundaries");
	return data[index];
}


int Stack::GetSize()
{
	return count + 1;
}

int Stack::GetCapacity()
{
	return capacity;
}

int Stack::Pop()
{
	if (count == -1) throw out_of_range("stack is empty");
	return data[count--];
}

void Stack::Push(int value)
{
	if (count + 1 >= capacity) throw out_of_range("stack is full");
	data[++count] = value;
}

int Stack::Peek()
{
	if (count == -1) throw out_of_range("stack is empty");
	return data[count];
}