//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0904_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0904_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 双指针：对满足要求的区间[i:j]，若j向右移动，我们可证明i必不会向左移动
public:
    int totalFruit(const vector<int> &fruits) {
        int ans = 0;
        unordered_map<int, int> counter;
        for (int l = 0, r = 0; r < (int) fruits.size(); ++r) {
            counter[fruits[r]]++;
            while (l < r && counter.size() > 2) {
                counter[fruits[l]]--;
                if (!counter[fruits[l]]) {
                    counter.erase(fruits[l]);
                }
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0904_H
