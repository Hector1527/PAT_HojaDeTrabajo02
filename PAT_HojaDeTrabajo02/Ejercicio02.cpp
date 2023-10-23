#include "Ejercicio02.h"
class Cola
{
private:
	struct Nodo {
		int num;
		Nodo* next = nullptr;
		Nodo(int n) : num(n) {}
	};

	Nodo* head = nullptr;
	Nodo* tail = nullptr;

public:
	void enqueue(int n)
	{
		if (this->empty())
		{
			this->head = this->tail = new Nodo(n);
		}
		else
		{
			this->tail->next = new Nodo(n);
			this->tail = this->tail->next;
		}
	}

	bool empty()
	{
		return this->head == nullptr;
	}

	int front()
	{
		return this->head->num;
	}

	int deque()
	{
		if (this->empty())
			return 0;

		Nodo* temp = this->head;
		int valor = temp->num;

		this->head = this->head->next;

		delete temp;
		return valor;
	}
};

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
	Cola cola1, cola2;
	while (l1 != nullptr)
	{
		cola1.enqueue(l1->value);
		l1 = l1->next;
	}
	while (l2 != nullptr)
	{
		cola2.enqueue(l2->value);
		l2 = l2->next;
	}

	Node<int>* result = nullptr;
	Node<int>* tail = nullptr;

	int acarreo = 0;
	while (!cola1.empty() || !cola2.empty() || acarreo) {
		int sum = acarreo;
		if (!cola1.empty()) {
			sum += cola1.deque();
		}
		if (!cola2.empty()) {
			sum += cola2.deque();
		}
		acarreo = sum / 10;
		int num1 = sum % 10;

		Node<int>* newnode = new Node<int>;
		newnode->value = num1;
		newnode->next = nullptr;

		if (result == nullptr)
		{
			result = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
	}

	return result;
}

