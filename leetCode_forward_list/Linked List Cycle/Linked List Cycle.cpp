#include "../Forward_list.h"
#include <iostream>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

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
    Solution solution;

    Forward_list list;
    list.push_back(3);
    list.push_back(2);
    list.push_back(0);
    list.push_back(-4);

    list.getNode(3)->next = list.getNode(1);

    std::cout << std::boolalpha << solution.hasCycle(list.getHead()) << endl;

    Forward_list list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.getNode(1)->next = list.getNode(0);

    std::cout << std::boolalpha << solution.hasCycle(list2.getHead()) << endl;

    Forward_list list3;
    list3.push_back(1);

    std::cout << std::boolalpha << solution.hasCycle(list3.getHead()) << endl;

    return 0;
}