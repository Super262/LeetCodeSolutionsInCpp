//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0384_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0384_H

#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
    // 直接背诵！
private:
    vector<int> nums;

public:
    Solution(const vector<int> &s) {
        nums = vector<int>(s);
    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        auto res = vector<int>(nums);
        const int n = (int) res.size();
        for (int i = 0; i < n; ++i) {
            swap(res[i], res[i + random() % (n - i)]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0384_H
