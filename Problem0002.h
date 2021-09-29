//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0002_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0002_H

class Problem0002 {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto dummyHead = new ListNode(-1);  // 虚拟头节点，避免额外的判断操作
        auto current = dummyHead;
        int t = 0;
        while (l1 || l2 || t) {
            if (l1) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                t += l2->val;
                l2 = l2->next;
            }
            current->next = new ListNode(t % 10);
            current = current->next;
            t /= 10;
        }
        return dummyHead->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0002_H
