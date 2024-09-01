//
// Created by mateo on 29/08/2024.
//

#include "../Forward_list.h"

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

/*
ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr) {
            return head;
        }

        ListNode* temp = head;

        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
 */

int main() {

    Forward_list<int> list;

    list.push_back(3);
    list.push_back(2);
    list.push_back(3);
    list.push_back(0);
    list.push_back(0);
    list.push_back(0);
    list.push_back(1);

    list.print();

    deleteSelect(list.getHead(), 0);

    list.print();
}