//
// Created by ASUS on 8/28/2024.
//

#ifndef FORWARDLIST_H
#define FORWARDLIST_H


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
    Forward_list(Node<T>* head) : head(head){}

    T front() {
        return head->data;
    }
    Node<T>* getHead() {
        return head;
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


    T operator[](int index) {
        Node<T>* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if(count == index) {
                return temp->data;
            }
            count++;
            temp =  temp->next;
        }
    }

    bool empty() {
        if(head == nullptr) {
            return true;
        }
        return false;
    }

    int size() {
        Node<T>* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void deleteValue(T value) {
        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == value) {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }

    void print() {
        Node<T>* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};


#endif //FORWARDLIST_H
