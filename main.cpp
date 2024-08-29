#include <iostream>

#include "ForwardList.h"

using namespace std;

void deleteSelect(Node<int>* head, int val) {
    Node<int>* temp = head;
    Node<int>* prev = nullptr;

    while(temp->next != nullptr) {
        if(temp->data == val) {
            prev->next = temp->next;
            temp = temp->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int calcularMCD(int a, int b) {
    while (b != 0) {
        int residuo = a % b;
        a = b;
        b = residuo;
    }
    return a;
}
void añadirGCD(Node<int>*head) {
    Node<int>* temp = head;

    while(temp->next != nullptr) {
        Node<int>* next = temp->next;
        int mcdValue = calcularMCD(temp->data, next->data);

        Node<int>* nuevo = new Node<int>(mcdValue);
        nuevo->next = next;

        temp->next = nuevo;
        temp = next;

    }
}


int main() {
    // Crear una lista enlazada de enteros
    Forward_list<int> list;

    // Agregar elementos a la lista
    list.push_back(18);
    list.push_back(6);
    list.push_back(10);
    list.push_back(3);

    cout << "Lista original: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;


    añadirGCD(list.getHead());
    cout << "Lista después de añadir gcd: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}
