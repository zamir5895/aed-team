//
// Created by mateo on 29/08/2024.
//

#include "../Forward_list.h"

using namespace std;

int mcd(int a, int b) {
    while (b != 0) {
        int residuo = a % b;
        a = b;
        b = residuo;
    }
    return a;
}

void mcdProb(Node<int>* head) {
    Node<int>* temp = head;

    while(temp->next != nullptr) {
        int val = mcd(temp->data, temp->next->data);
        Node<int>* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
}

int main() {
    Forward_list<int> list;

    list.push_back(18);
    list.push_back(6);
    list.push_back(10);
    list.push_back(3);

    list.print();

    mcdProb(list.getHead());

    list.print();

    return 0;
}