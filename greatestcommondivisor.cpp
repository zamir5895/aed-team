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

int gcd (int a, int b ){
    if(b>a){
        return gcd(b,a);
    }
    if(a*b==0){
        return 0;
    }
    return a%b==0?b:gcd(b,a%b);
}
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* aux = head;
        while(aux != nullptr && aux->next != nullptr){
            ListNode* temp = aux->next;
            int valor = gcd(aux->val, temp->val);
            ListNode* nuevo = new ListNode(valor);
            nuevo->next = temp;
            aux->next = nuevo;
            aux = temp;

            
        }
    return head;}
};