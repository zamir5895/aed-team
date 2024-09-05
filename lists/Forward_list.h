//
// Created by mateo on 27/08/2024.
//

#ifndef FORWARD_LIST_FORWARD_LIST_H
#define FORWARD_LIST_FORWARD_LIST_H

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Forward_list {
private:
    ListNode* head;

public:
    Forward_list() : head(nullptr) {}

    Forward_list(ListNode* head) : head(head) {}

    ListNode* getHead() {
        return head;
    }

    ListNode* getTail() {
        ListNode* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

    int front() {
        return head->val;
    }

    int back() {
        ListNode* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->val;
    }

    void push_front(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void push_back(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr){
            head = newNode;
        } else{
            ListNode* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int pop_front() {
        ListNode* temp = head;
        int nodeValue = head->val;
        head = head->next;
        delete temp;
        return nodeValue;
    }

    int pop_back() {

        if(head->next == nullptr) {
            int nodeValue = head->val;
            delete head;
            head = nullptr;
            return nodeValue;
        }

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        int nodeValue = temp->val;
        prev->next = nullptr;
        delete temp;

        return nodeValue;
    }

    void insert(int val, int pos) {
        ListNode* newNode = new ListNode(val);

        if(pos == 0) {
            push_back(val);
        } else {
            ListNode* temp = head;
            for(int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int operator[](int pos) {
        ListNode* temp = head;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
        return temp->val;
    }

    ListNode* getNode(int pos) {
        ListNode* temp = head;
        for(int i = 0; i < pos; i++) {
            if(temp == nullptr) {
                return nullptr;
            }
            temp = temp->next;
        }
        return temp;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void clear() {
        while(!empty()){
            pop_back();
        }
    }

    void reverse() {
        if(head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* prev = nullptr;
        ListNode* act = head;
        ListNode* next;

        while(act != nullptr) {
            next = act->next;
            act->next = prev;
            prev = act;
            act = next;
        }
        head = prev;
    }

    void print() {
        ListNode* temp = head;
        while(temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif //FORWARD_LIST_FORWARD_LIST_H