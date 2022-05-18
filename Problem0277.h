//
// Created by Fengwei Zhang on 5/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0277_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0277_H

// The knows API is defined for you.
bool knows(int a, int b);

class Solution {
    // 贪心算法：若knows(a,b)返回false，说明b不是名人，a可能是名人
    // 可能的改进：重写knows，加入缓存
public:
    int findCelebrity(int n) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (!knows(i, ans)) {
                ans = i;
            }
        }
        if (!validCelebrity(ans, n)) {
            return -1;
        }
        return ans;
    }

private:
    bool validCelebrity(int x, int n) {
        for (int i = 0; i < n; ++i) {
            if (i == x) {
                continue;
            }
            if (knows(x, i) || !knows(i, x)) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0277_H
