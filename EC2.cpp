//
// Created by ASUS on 8/29/2024.
//

#include <iostream>
#include <list>


using namespace std;


 struct Node {
     int val;
     Node *next;
     Node() : val(0), next(nullptr) {}
     Node(int x) : val(x), next(nullptr) {}
     Node(int x, Node *next) : val(x), next(next) {}

 };

class Solution {
public:
    int calcularMCD(int a, int b) {
        while (b != 0) {
            int residuo = a % b;
            a = b;
            b = residuo;
        }
        return a;
    }

    Node* GCD(Node* head) {
        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            Node* next = temp->next;
            int mcdValue = calcularMCD(temp->val, next->val);

            Node* nuevo = new Node(mcdValue);
            nuevo->next = next;

            temp->next = nuevo;
            temp = next;
        }

        return head;
    }
};

/*
int main() {
    // Crear una lista enlazada de enteros
    Node<int> list;
*/

    /*
    list.push_back(18);
    list.push_back(6);
    list.push_back(10);
    list.push_back(3);
*/

    /*
    cout << "Lista original: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    Solution::GCD(list.getHead());
    cout << "Lista despues de añadir gcd: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;

}
*/