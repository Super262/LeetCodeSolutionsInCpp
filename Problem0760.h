//
// Created by Fengwei Zhang on 7/27/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0760_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0760_H

#include <vector>
#include <unordered_map>

using namespace std;

class Problem0760 {
    // 使用哈希表记录nums2每种元素的索引，再根据nums1的每个元素生成答案
public:
    vector<int> anagramMappings(const vector<int> &nums1, const vector<int> &nums2) {
        unordered_map<int, vector<int>> num_idx;
        for (int i = 0; i < (int) nums2.size(); ++i) {
            num_idx[nums2[i]].emplace_back(i);
        }
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < (int) nums1.size(); ++i) {
            ans[i] = num_idx[nums1[i]].back();
            num_idx[nums1[i]].pop_back();
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0760_H
