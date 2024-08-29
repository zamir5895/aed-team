#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    // Crear nodos
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Conectar nodos para formar una lista con ciclo: 3 -> 2 -> 0 -> -4 -> 2 ...
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Crear el ciclo aquí

    Solution solution;

    if(solution.hasCycle(node1)) {
        std::cout << "La lista tiene un ciclo." << std::endl;
    } else {
        std::cout << "La lista no tiene un ciclo." << std::endl;
    }

    // Liberar la memoria (aunque en este caso, la lista tiene un ciclo, así que la liberación completa es complicada)
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}