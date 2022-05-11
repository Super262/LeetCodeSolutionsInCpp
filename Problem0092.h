//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0092_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0092_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, const int left, const int right) {
        if (!head || right - left + 1 < 2) {
            return head;
        }
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto a = dummy;
        for (int i = 0; i < left - 1; ++i) {  // 将a移动到第(left-1)个节点
            a = a->next;
        }
        auto b = a->next;
        auto c = b->next;
        for (int i = 0; i < right - left; ++i) {  // 应反转(right-left)个指针
            auto t = c->next;
            c->next = b;
            b = c;
            c = t;
        }
        a->next->next = c;
        a->next = b;
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0092_H
