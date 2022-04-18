//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0969_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0969_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 倒推：思考如何把有序序列转化成输入的arr
    // 解法：从后向前遍历，找到前缀[0:i]的最大值，其索引为k；翻转[0:k]，再翻转[0:i]，最大值落在答案的位置i上
public:
    vector<int> pancakeSort(vector<int> &arr) {
        vector<int> ans;
        for (auto i = (int) arr.size() - 1; i >= 0; --i) {
            int k = 0;
            for (int j = 1; j <= i; ++j) {
                if (arr[j] <= arr[k]) {
                    continue;
                }
                k = j;
            }
            if (k == i) {
                continue;
            }
            ans.emplace_back(k + 1);
            reverse(arr.begin(), arr.begin() + (k + 1));
            ans.emplace_back(i + 1);
            reverse(arr.begin(), arr.begin() + (i + 1));
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0969_H
