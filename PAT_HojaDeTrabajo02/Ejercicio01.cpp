#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    if (head == nullptr || k == 0)
    {
        return head;
    }

    Node<char>* tail = head;
    int nodos = 0;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        nodos++;
    }

    Node<char>* Rotate = head;
    for (int i = 0; i < nodos-k; i++)
    {
        Rotate = Rotate->next;
    }

    Node<char>* result = Rotate;
    Rotate->next = nullptr;
    tail->next = head;


    return head;
}
