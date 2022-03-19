//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0437_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0437_H

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
    // 借鉴前缀和计算
public:
    int pathSum(TreeNode *root, int targetSum) {
        unordered_map<int, int> counter;  // counter[s]：当前搜索路径上和为s的前缀和的个数
        counter[0] = 1;  // 不要忘记前缀和的起点：0
        int result = 0;
        dfs(root, 0, targetSum, result, counter);
        return result;
    }

private:
    void dfs(TreeNode *root, int current, int target, int &result, unordered_map<int, int> &counter) {
        if (!root) {
            return;
        }
        current += root->val;
        result += counter.count(current - target) ? counter[current - target] : 0;  // 采用类似前缀和的计算方式
        ++counter[current];
        dfs(root->left, current, target, result, counter);
        dfs(root->right, current, target, result, counter);
        --counter[current];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0437_H
