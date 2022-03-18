//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0508_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0508_H

#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        vector<int> res;
        int max_freq = 0;
        unordered_map<int, int> freq;
        dfs(root, freq, max_freq);
        for (const auto &x: freq) {
            if (x.second == max_freq) {
                res.emplace_back(x.first);
            }
        }
        return res;
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
