#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
	if (!head)
		return nullptr;

	Node<char>* tail = head;
	int nodos = 1;

	while (tail->next)
	{
		tail = tail->next;
		nodos++;
	}

	k = k % nodos;

	if (k == 0)
		return head;

	Node<char>* temp = head;
	for (int i = 0; i < nodos-k-1; i++)
	{
		temp = temp->next;
	}

	Node<char>* result = temp->next;
	temp->next = nullptr;
	tail->next = head;

	return result;
}

