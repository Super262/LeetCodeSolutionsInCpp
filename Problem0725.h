//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0725_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0725_H

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) {
            ++n;
        }
        vector<ListNode *> res;
        res.reserve(k);
        auto p = head;
        for (int i = 0; i < k; ++i) {
            auto length = n / k;
            if (i < n % k) {
                ++length;
            }
            res.emplace_back(p);
            for (int j = 0; j < length - 1; ++j) {  // 找到最后结点的前驱
                p = p->next;
            }
            if (p) {  // 细节：别忘记"断链"
                auto q = p->next;
                p->next = nullptr;
                p = q;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0725_H
