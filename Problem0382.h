//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0382_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0382_H

#include <cstdlib>
#include "listnode.h"

using namespace std;

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
