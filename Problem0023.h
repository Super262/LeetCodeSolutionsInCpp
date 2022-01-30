//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0023_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0023_H

#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 堆的经典应用
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, nodeGreater> heap;
        for (auto lh: lists) {
            if (!lh) {
                continue;
            }
            heap.emplace(lh);
        }
        auto dummyHead = new ListNode(-1);
        auto current = dummyHead;
        while (!heap.empty()) {
            auto lh = heap.top();
            heap.pop();
            current->next = lh;
            current = current->next;
            if (lh->next) {
                heap.emplace(lh->next);
            }
        }
        return dummyHead->next;
    }

private:
    struct nodeGreater {
        bool operator()(ListNode *a, ListNode *b) const {
            return a->val > b->val;
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0023_H
