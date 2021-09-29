//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0021_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0021_H

class Problem0021 {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        auto dummyNode = new ListNode(-1);
        dummyNode->next = l1;
        auto resCur = dummyNode;
        auto l2Cur = l2;
        ListNode *l2Next;
        while (l2Cur && resCur->next) {
            if (resCur->next->val >= l2Cur->val) {
                l2Next = l2Cur->next;
                l2Cur->next = resCur->next;
                resCur->next = l2Cur;
                l2Cur = l2Next;
            } else {
                resCur = resCur->next;
            }
        }
        if (l2Cur) {
            resCur->next = l2Cur;
        }
        return dummyNode->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0021_H
