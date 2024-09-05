//
// Created by mateo on 4/09/2024.
//

#include "../Forward_list.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* c = nullptr;
        ListNode* d = nullptr;

        ListNode* temp = head;

        while (temp != nullptr){
            if(temp->val < x) {
                if(a == nullptr) {
                    a = temp;
                    b = temp;
                } else{
                    b->next = temp;
                    b = b->next;
                }
            } else {
                if(c == nullptr) {
                    c = temp;
                    d = temp;
                } else {
                    d->next = temp;
                    d = d->next;
                }
            }
            temp = temp->next;
        }
        d->next = nullptr;

        if(a == nullptr) {
            return c;
        }

        b->next = c;

        return a;
    }
};