//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0508_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0508_H

#include <vector>
#include <unordered_map>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似后序遍历：先求出左、右子树的元素和，再计算当前子树的元素和，更新元素和的频率和最大频率；最后，输出频率为最大频率的元素和
public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        int max_freq = 0;
        unordered_map<int, int> freq;
        dfs(root, freq, max_freq);
        vector<int> ans;
        for (const auto &x: freq) {
            if (x.second == max_freq) {
                ans.emplace_back(x.first);
            }
        }
        return ans;
    }

private:
    int dfs(TreeNode *root, unordered_map<int, int> &freq, int &max_freq) {
        if (!root) {
            return 0;
        }
        auto sum = dfs(root->left, freq, max_freq) + dfs(root->right, freq, max_freq);
        sum += root->val;
        ++freq[sum];
        if (freq[sum] > max_freq) {
            max_freq = freq[sum];
        }
        return sum;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0508_H
