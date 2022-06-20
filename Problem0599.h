//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0599_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0599_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 找到l1、l2的公共元素，再比较索引和
public:
    vector<string> findRestaurant(const vector<string> &l1, const vector<string> &l2) {
        unordered_map<string, int> s1_to_idx;
        for (int i = 0; i < l1.size(); ++i) {
            s1_to_idx[l1[i]] = i;
        }
        auto idx_sum = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < l2.size(); ++i) {
            const auto &s2 = l2[i];
            if (!s1_to_idx.count(s2)) {
                continue;
            }
            auto temp = i + s1_to_idx[s2];
            if (temp < idx_sum) {
                idx_sum = temp;
                ans = {s2};
            } else if (temp == idx_sum) {
                ans.emplace_back(s2);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0599_H
