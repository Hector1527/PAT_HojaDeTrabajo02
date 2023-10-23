#include "Ejercicio03.h"

template <typename T>
class Pila
{
private:
	struct Nodo
	{
		T num;
		Nodo* next = nullptr;
		Nodo(int n) : num(n) {}
	};
	Nodo* head = nullptr;
public:
	bool empty()
	{
		return this->head == nullptr;
	}

	void push(T n)
	{
		Nodo* nodo = new Nodo(n);
		nodo->next = head;
		head = nodo;
	}

	int peek()
	{
		return head->num;
	}

	int pop()
	{
		if (empty())
			return 0;

		Nodo* temp = head;
		int valor = temp->num;

		head = head->next;

		delete temp;
		return valor;
	}

};

int Ejercicio03::calculate(string s)
{
	Pila<int> numeros;
	Pila<char> operadores;

	int num = 0;
	char signo = '+';
	int result = 0;

	for (char a : s)
	{
		if (a == ' ')
			continue;

		if (isdigit(a))
		{
			num = num * 10 + (a - '0');
		}
		else
		{
			if (signo == '+')
			{
				numeros.push(num);
			}
			else if (signo == '-')
			{
				numeros.push(-num);
			}
			else if (signo == '*')
			{
				int num2 = numeros.pop();
				numeros.push(num2 * num);
			}
			else if (signo == '/')
			{
				int num2 = numeros.pop();
				numeros.push(num2 / num);
			}

			num = 0;
			signo = a;
		}
	}

	if (signo == '+')
	{
		numeros.push(num);
	}
	else if (signo == '-')
	{
		numeros.push(-num);
	}
	else if (signo == '*')
	{
		int num2 = numeros.pop();
		numeros.push(num2 * num);
	}
	else if (signo == '/')
	{
		int num2 = numeros.pop();
		numeros.push(num2 / num);
	}

	while (!numeros.empty())
	{
		result += numeros.pop();
	}
	return result;
}

