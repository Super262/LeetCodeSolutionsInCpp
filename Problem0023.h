//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0023_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0023_H

#include <vector>
#include <queue>
#include "listnode.h"

using namespace std;

class Problem0023 {
    // 直接背诵，堆的经典应用：掌握比较器（结构体类型）的实现
public:
    ListNode *mergeKLists(const vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, NodeGreater> heap;
        for (const auto &l: lists) {
            if (!l) {
                continue;
            }
            heap.emplace(l);
        }
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while (!heap.empty()) {
            auto node = heap.top();
            heap.pop();
            if (node->next) {
                heap.emplace(node->next);
                node->next = nullptr;
            }
            cur->next = node;
            cur = cur->next;
        }
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }

private:
    struct NodeGreater {
        bool operator()(ListNode *a, ListNode *b) const {
            return a->val > b->val;
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0023_H
