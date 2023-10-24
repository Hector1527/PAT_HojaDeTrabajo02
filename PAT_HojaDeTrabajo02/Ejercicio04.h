#pragma once
class FrontMiddleBackQueue
{
public:
	struct Nodo
	{
		int num;
		Nodo* next = nullptr;
		Nodo(int value) : num(value) {}
	};
	Nodo* head = nullptr;
	Nodo* tail = nullptr;

	FrontMiddleBackQueue();

	void pushFront(int value);

	void pushMiddle(int value);

	void pushBack(int value);

	int popFront();

	int popMiddle();

	int popBack();
};

