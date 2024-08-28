//
// Created by mateo on 27/08/2024.
//

#ifndef FORWARD_LIST_FORWARD_LIST_H
#define FORWARD_LIST_FORWARD_LIST_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Forward_list {
private:
    Node<T>* head;

public:
    Forward_list() : head(nullptr) {}

    T front() {
        return head->data;
    }

    T back() {
        Node<T>* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);

        if (head == nullptr){
            head = newNode;
        } else{
            Node<T>* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    T pop_front() {
        Node<T>* temp = head;
        T nodeValue = head->data;
        head = head->next;
        delete temp;
        return nodeValue;
    }

    T pop_back() {

        if(head->next == nullptr) {
            T nodeValue = head->data;
            delete head;
            head = nullptr;
            return nodeValue;
        }

        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        while(temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        T nodeValue = temp->data;
        prev->next = nullptr;
        delete temp;

        return nodeValue;
    }

    void insert(T val, int pos) {
        Node<T>* newNode = new Node<T>(val);

        if(pos == 0) {
            push_back(val);
        } else {
            Node<T>* temp = head;
            for(int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
};

#endif //FORWARD_LIST_FORWARD_LIST_H
