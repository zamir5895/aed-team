//
// Created by mateo on 29/08/2024.
//

#include <iostream>

struct Node {
    int val;
    Node* next;

    Node(int data) : val(data), next(nullptr) {}
};

Node* solucion1(Node* head, int val) {
    while (head != nullptr && head->val == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == nullptr) {
        return head;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->next->val == val) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        } else {
            temp = temp->next;
        }
    }

    return head;
}


int main() {

    /*
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    print(node1);

    Solucion1(node1, 6);

    print(node1);

     */
    return 0;
}