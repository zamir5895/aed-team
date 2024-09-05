//
// Created by mateo on 4/09/2024.
//

#ifndef AED_TEAM_DOUBLY_LINKED_LIST_H
#define AED_TEAM_DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class Doubly_Linked_List {
private:
    ListNode* head;
    ListNode* tail;

public:
    Doubly_Linked_List() : head(nullptr), tail(nullptr) {}

    int front() {
        return head->val;
    }

    int back() {
        return tail->val;
    }

    void push_front(int x) {
        ListNode* newNode = new ListNode(x);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int x) {
        ListNode* newNode = new ListNode(x);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pop_front() {
        if (head == nullptr) return -1; // Empty list

        ListNode* temp = head;
        int nodeValue = head->val;

        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr; // List becomes empty

        delete temp;
        return nodeValue;
    }

    int pop_back() {
        if (tail == nullptr) return -1; // Empty list

        ListNode* temp = tail;
        int nodeValue = tail->val;

        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr; // List becomes empty

        delete temp;
        return nodeValue;
    }

    void insert(int val, int pos) {
        if (pos == 0) {
            push_front(val);
            return;
        }

        ListNode* newNode = new ListNode(val);
        ListNode* temp = head;

        for (int i = 0; i < pos - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            push_back(val);
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;

        if (newNode->next == nullptr)
            tail = newNode;
    }

    int operator[](int pos) {
        ListNode* temp = head;
        for(int i = 0; i < pos; i++){
            if (temp == nullptr) return -1; // Position out of bounds
            temp = temp->next;
        }
        return temp->val;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void reverse() {
        ListNode* temp = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            tail = head;
            head = temp->prev;
        }
    }

    void print() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif //AED_TEAM_DOUBLY_LINKED_LIST_H