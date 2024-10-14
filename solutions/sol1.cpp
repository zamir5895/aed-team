#include "../lists/Forward_list.h"
#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previo = nullptr;
        ListNode* actual = head;
        ListNode* siguiente = nullptr;
        while (actual != nullptr) {
            siguiente = actual->next;
            actual->next = previo;
            previo = actual;
            actual = siguiente;
        }
        head = previo;
        return head;
    }
};