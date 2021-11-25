//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0382_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0382_H

#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // Reservoir Sampling: https://www.acwing.com/solution/content/14526/
private:
    ListNode *head;
public:
    Solution(ListNode *h) {
        head = h;
    }

    int getRandom() {
        int result = -1;
        int k = 0;
        for (auto p = head; p; p = p->next) {
            ++k;
            if (random() % k) {
                continue;
            }
            result = p->val;
        }
        return result;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0382_H
