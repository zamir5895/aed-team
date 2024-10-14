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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        ListNode* mid = head;
        int count = 0;

        while(temp != nullptr) {
            temp = temp->next;
            count++;
        }

        count = count / 2;

        for(int i = 0; i < count; i++) {
            mid = mid->next;
        }

        return mid;
    }
};