//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0528_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0528_H

#include <vector>

using namespace std;

class Solution {
public:
    Solution(const vector<int> &w) {
        n = (int) w.size();
        prefix.emplace_back(0);
        prefix.insert(prefix.end(), w.begin(), w.end());
        for (int i = 2; i <= n; ++i) {
            prefix[i] += prefix[i - 1];
        }
    }

    int pickIndex() {
        auto k = (int) (random() % prefix.back() + 1);
        int l = 1, r = n;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (prefix[mid] >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r - 1;
    }

private:
    vector<int> prefix;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0528_H
