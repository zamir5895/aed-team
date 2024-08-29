#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                ListNode* cycleStart = head;
                while(cycleStart != slow) {
                    cycleStart = cycleStart->next;
                    slow = slow->next;
                }
                return cycleStart;
            }
        }

        return nullptr;
    }
};

// Helper function to create a linked list with a cycle
ListNode* createListWithCycle() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; // Creates a cycle

    return head;
}

int main() {
    Solution solution;
    ListNode* head = createListWithCycle();
    ListNode* cycleStart = solution.detectCycle(head);

    if (cycleStart) {
        std::cout << "Cycle detected starting at node with value: " << cycleStart->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}