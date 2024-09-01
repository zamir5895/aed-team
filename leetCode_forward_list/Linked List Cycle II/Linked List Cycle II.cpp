#include <iostream>
#include "../Forward_list.h"

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

int main() {
    Solution solution;

    Forward_list list;
    list.push_back(3);
    list.push_back(2);
    list.push_back(0);
    list.push_back(-4);
    list.getTail()->next = list.getHead()->next;

    std::cout << solution.detectCycle(list.getHead())->val;

    return 0;
}