#include <iostream>


  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
        ListNode* actual = head;
        ListNode* anterior = nullptr;
        ListNode* siguiente;
        int cont = 0;
        while(actual!=nullptr){
            siguiente = actual->next;
            actual->next = anterior;
            anterior = actual;
            actual = siguiente;
            cont++;
        }
        head = anterior;
        ListNode* auxi = head;
        for(int i = 1; i < n && auxi != nullptr; ++i){
            auxi = auxi->next;
        }
        if(head->next==nullptr){
            head = head->next;
            return head;
        }
        auxi->next = auxi->next->next;

        ListNode* actual2 = head;
        ListNode* anterior2 = nullptr;
        ListNode* siguiente2;
        while(actual2 != nullptr){
            siguiente2 = actual2->next;
            actual2->next = anterior2;
            anterior2 = actual2;
            actual2 = siguiente2;
        }
        head = anterior2;
        return head;       
    }
};