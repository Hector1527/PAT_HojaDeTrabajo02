#include "Ejercicio04.h"
#include <iostream>

FrontMiddleBackQueue::FrontMiddleBackQueue()
{
}



void FrontMiddleBackQueue::pushFront(int value)
{
	if (head == nullptr)
	{
		head = tail = new Nodo(value);
	}
	else
	{
		Nodo* temp = new Nodo(value);
		temp->next = head;
		head = temp;
	}
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
	Nodo* temp = new Nodo(value);

	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		Nodo* corto = head;
		Nodo* largo = head;
		Nodo* prev = nullptr;

		while (largo != nullptr && largo->next != nullptr)
		{
			largo = largo->next->next;
			prev = corto;
			corto = corto->next;
		}

		if (prev == nullptr)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			temp->next = corto;
			prev->next = temp;
		}
	}
}

void FrontMiddleBackQueue::pushBack(int value)
{

	if (head == nullptr)
	{
		head = tail = new Nodo(value);
	}
	else
	{
		Nodo* temp = new Nodo(value);
		tail->next = temp;
		tail = temp;
	}
}

int FrontMiddleBackQueue::popFront()
{
	if (head == nullptr)
		return -1;

	Nodo* temp = head;
	int valor = temp->num;
	head = head->next;

	delete temp;
	return valor;
}

int FrontMiddleBackQueue::popMiddle()
{
	if (head == nullptr)
		return -1;

	Nodo* prev = nullptr;
	Nodo* corto = head;
	Nodo* largo = head;
	Nodo* prevprev = nullptr;
	int cantidad = 0;

	while (largo != nullptr && largo->next != nullptr)
	{
		prevprev = prev;
		largo = largo->next->next;
		prev = corto;
		corto = corto->next;
		cantidad += 2;
	}

	if (largo != nullptr)
		cantidad += 1;

	if (cantidad == 1)
	{
		int valor = largo->num;
		head = head->next;
		return valor;
	}

	if (cantidad == 2)
	{
		int valor = head->num;
		Nodo* temp = head;
		head = head->next;
		delete temp;
		return valor;
	}
	else {
		if (prev == nullptr)
		{
			head = corto->next;
		}
		else if (cantidad % 2 == 0)
		{
			int valor = prev->num;
			prevprev->next = prev->next;
			delete prev;
			return valor;
		}
		else
		{
			int valor = corto->num;
			prev->next = corto->next;
			delete corto;
			return valor;
		}
	}
}

int FrontMiddleBackQueue::popBack()
{

	if (head == nullptr)
		return -1;

	Nodo* temp = head;
	Nodo* prev = nullptr;

	while (temp->next != nullptr)
	{
		prev = temp;
		temp = temp->next;
	}
	int valor = temp->num;

	if (prev != nullptr)
	{
		prev->next = nullptr;
		tail = prev;
	}
	else
	{
		head = nullptr;
		tail = nullptr;
	}

	delete temp;
	return valor;
}