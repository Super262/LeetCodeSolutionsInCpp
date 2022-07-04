//
// Created by Fengwei Zhang on 7/3/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0663_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0663_H

#include "treenode.h"
#include <unordered_map>

using namespace std;

class Solution {
    // 类似后序遍历，我们用哈希表sum_cnt统计每棵子树的元素和，并获得root的元素和total
    // 我们检查sum_cnt[total/2]>0是否成立；total可能为0，0/2还是0，所以一定要执行sum_cnt[total]--
public:
    bool checkEqualTree(TreeNode *root) {
        if (!root) {
            return false;
        }
        unordered_map<int, int> sum_cnt;
        auto total = dfs(root, sum_cnt);
        sum_cnt[total]--;
        if (total % 2 || !sum_cnt[total / 2]) {
            return false;
        }
        return true;
    }

private:
    int dfs(TreeNode *root, unordered_map<int, int> &sum_cnt) {
        auto sum = root->val;
        if (root->left) {
            sum += dfs(root->left, sum_cnt);
        }
        if (root->right) {
            sum += dfs(root->right, sum_cnt);
        }
        sum_cnt[sum]++;
        return sum;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0663_H
