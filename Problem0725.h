//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0725_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0725_H

#include <vector>
#include "listnode.h"

using namespace std;

class Problem0725 {
    // 首先，遍历链表，获得总长度n；设r=n%k，l=n/k，当前区段的索引为i；若i<r，区段i的节点个数为l+1；若i>=r，区段i的节点个数为l（0<=i<=n-1）
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) {
            ++n;
        }
        vector<ListNode *> ans;
        ans.reserve(k);
        auto p = head;
        for (int i = 0; i < k; ++i) {
            auto length = n / k;
            if (i < n % k) {
                ++length;
            }
            ans.emplace_back(p);
            for (int j = 0; j < length - 1; ++j) {  // 找到最后结点的前驱
                p = p->next;
            }
            if (p) {  // 细节：别忘记"断链"
                auto q = p->next;
                p->next = nullptr;
                p = q;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0725_H
