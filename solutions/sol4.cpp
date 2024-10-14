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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* FirstPar = nullptr;
        ListNode* LastPar = nullptr;
        ListNode* FirstImpar = nullptr;
        ListNode* LastImpar = nullptr;

        int contador = 0;

        if(head->next == nullptr) {
            return head;
        }

        while (head != nullptr) {
            if (contador % 2 == 0) {
                if (FirstPar == nullptr) {
                    FirstPar = head;
                    LastPar = head;
                } else {
                    LastPar->next = head;
                    LastPar = LastPar->next;
                }
            } else {
                if (FirstImpar == nullptr) {
                    FirstImpar = head;
                    LastImpar = head;
                } else {
                    LastImpar->next = head;
                    LastImpar = LastImpar->next;
                }
            }
            contador += 1;
            head = head->next;
        }

        LastPar->next = FirstImpar;
        LastImpar->next = nullptr;
        return FirstPar;
    }

};