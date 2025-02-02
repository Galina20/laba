#pragma once
#include "Storage.h"
#include "UnidirectionalList.h"
template<typename T>
class QueueBasedOnUnidirectionalList : public Storage<T>
{
	UnidirectionalList<T> *Queue;
	int count;
public:
	QueueBasedOnUnidirectionalList(int count)
		: Queue(), count(count) { }
	QueueBasedOnUnidirectionalList(const QueueBasedOnUnidirectionalList &other) //����������� �����������
	{
		Queue = other.Queue;
		count = other.count;
	}
	QueueBasedOnUnidirectionalList(QueueBasedOnUnidirectionalList &&other)
	{
		Queue = other.Queue;
		count = other.count;
	}
	QueueBasedOnUnidirectionalList<T> &operator=(const QueueBasedOnUnidirectionalList &other)
	{
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Queue = other.Queue;
	}
	QueueBasedOnUnidirectionalList<T> &operator=(QueueBasedOnUnidirectionalList &&other)
	{
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Queue = other.Queue;
	}

	~QueueBasedOnUnidirectionalList();

	void Push(T element) override  //������� (����������) ��������
	{
		if (Queue->GetSize() < count)
		{
			Queue->Push(element, Queue->GetSize());
		}
	}

	T Pop() override  //�������� (������) ��������
	{
		return Queue->Remove(1);
	}

	T Peek() override  //�������� (������ ��� ��������) ��������
	{
		return Queue->Peek(1);
	}

	bool CheckNoEmptyQueue() override  //�������� ������� ���������
	{
		return Queue->CheckNoEmptyList();
	}

	friend ostream & operator << <T>(ostream & stream, const QueueBasedOnUnidirectionalList<T> &a); //�����
};
template<typename T>
QueueBasedOnUnidirectionalList<T>::~QueueBasedOnUnidirectionalList()
{
	delete Queue;
}
template<typename T>
ostream & operator << (ostream & stream, const QueueBasedOnUnidirectionalList<T> &a) //�����
{
	QueueBasedOnUnidirectionalList<T> b = a;
	stream << "=====\n";
	for (int i = 0; i < b.count; i++)
	{
		stream << "| " << b.Pop() << "\n";
	}
	stream << "=====\n";
	return stream;
}
