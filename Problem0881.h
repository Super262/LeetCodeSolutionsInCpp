//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0881_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0881_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 贪心算法：让最重的和最轻的人坐同一艘船
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        for (int l = 0, r = (int) people.size() - 1; l <= r; --r) {
            if (people[l] + people[r] <= limit) {
                ++l;
            }
            ++ans;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0881_H
