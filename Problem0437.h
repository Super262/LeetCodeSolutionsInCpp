//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0437_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0437_H

#include <vector>
#include <unordered_map>
#include "treenode.h"

using namespace std;

class Solution {
    // 先序遍历+前缀和：我们要找到路径(s,t)，使得prefix[s]-prefix[t]=target成立
    // 我们使用哈希表记录前缀和的频率
public:
    int pathSum(TreeNode *root, int target) {
        unordered_map<long long, int> counter;  // counter[s]：当前搜索路径上和为s的前缀和的个数
        int ans = 0;
        counter[0] = 1;  // 不要忘记前缀和的起点：0
        dfs(root, 0, target, ans, counter);
        return ans;
    }

private:
    void dfs(TreeNode *root, long long sum, int target, int &ans, unordered_map<long long, int> &counter) {
        if (!root) {
            return;
        }
        sum += root->val;
        ans += counter.count(sum - target) ? counter[sum - target] : 0;  // 采用类似前缀和的计算方式
        auto &cnt = counter[sum];
        ++cnt;
        dfs(root->left, sum, target, ans, counter);
        dfs(root->right, sum, target, ans, counter);
        --cnt;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0437_H
