#include<iostream>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 class Solution{
    public:
    ListNode* swapPairs(ListNode* head) {
        
            ListNode* temphead = head;
            ListNode* anterior = nullptr;
            while(temphead != nullptr && temphead->next != nullptr){
                ListNode* temporal = temphead->next;
                if(anterior == nullptr){
                    head = temporal; //cambio de head
                }
                else{
                    anterior->next = temporal; //cambio de puntero anterior
                }
                temphead->next = temporal->next;
                temporal->next = temphead;
                anterior = temphead;
                temphead = temphead->next;
            }
            return head;
        
    }
 };

 int main(){

 }