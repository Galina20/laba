#include "Queue.h"
#include "QueueBasedOnArray.h"
#include "QueueBasedOnUnidirectionalList.h"
#include "QueueBasedOnBidirectionalCircularList.h"
#include "FactoryMethod.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	int n = 10;
	//патерн "Стратегия"
	Queue<int> queue;

	QueueBasedOnArray<int> queue1(n);
	QueueBasedOnUnidirectionalList<int> queue2(n);
	QueueBasedOnBidirectionalCircularList<int> queue3(n);

	queue.setStrategy(&queue1);
	queue.Push(2);
	queue.Push(5);
	cout << queue.Pop() << "\n";
	cout << queue.Peek() << "\n";

	queue.setStrategy(&queue2);
	queue.Push(3);
	queue.Push(6);
	cout << queue.Pop() << "\n";
	cout << queue.Peek() << "\n";

	queue.setStrategy(&queue3);
	queue.Push(8);
	queue.Push(1);
	cout << queue.Pop() << "\n";
	cout << queue.Peek() << "\n";
	delete &queue;
	//патерн "Фабричный метод"
	ConcreteCreatorQueueBasedOnArray<int> Creator1;
	ConcreteCreatorQueueBasedOnUnidirectionalList<int> Creator2;
	ConcreteCreatorQueueBasedOnBidirectionalCircularList<int> Creator3;
	Creator<int> *creators[3] = { &Creator1, &Creator2, &Creator3 };
	for (int i = 0; i < 3; i++)
	{
		Storage<int> *queue = creators[i]->factoryMethod(n);
		queue->Push(4);
		queue->Push(7);
		cout << queue->Pop() << "\n";
		cout << queue->Peek() << "\n";
		delete queue;
	}
	_getch();
}