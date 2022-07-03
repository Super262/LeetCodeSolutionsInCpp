//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0654_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0654_H

#include <vector>
#include <cmath>
#include "treenode.h"

using namespace std;

class Solution {
    // 根据题意，对于任意可能的区间nums[l:r]，我们需要查找区间nums[l:r]的最大值，根结点的值为max(nums[l:r])
    // 如果每次查找都全遍历区间nums[l:r]，总的时间复杂度为O(n^2)；我们可以用RMQ算法优化查找速度
    // RMQ是动态规划，采用倍增思想，f[i][j]是区间nums[i,i+(2^j)-1]的最大值；因此f[i][j]=max(f[i][j-1], f[i+2^(j-1)][j-1])
    // 对于区间nums[l:r]，很有可能区间长度r-l+1不等于2^k，因此我们需要比较f[l][k]和f[r-(1<<k)+1][k]，k=log(r-l+1)/log(2)
    // 我们用与处理得到的数组f，建立满足题意的二叉树，总的时间复杂度为O(N*logN)
public:
    TreeNode *constructMaximumBinaryTree(const vector<int> &nums) {
        const auto n = (int) nums.size();
        const auto k = (int) (log(n) / log(2));
        vector<vector<int>> f(n, vector<int>(k + 1, 0));  // 根据题意，这里f[i][j]记录的是最大值的索引
        for (int j = 0; j <= k; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                if (!j) {
                    f[i][j] = i;
                    continue;
                }
                auto l = f[i][j - 1];
                auto r = f[i + (1 << (j - 1))][j - 1];
                if (nums[l] > nums[r]) {
                    f[i][j] = l;
                } else {
                    f[i][j] = r;
                }
            }
        }
        return build(0, n - 1, f, nums);
    }

private:
    int query(int l, int r, const vector<vector<int>> &f, const vector<int> &nums) {
        auto length = r - l + 1;
        auto k = (int) (log(length) / log(2));
        auto a = f[l][k];
        auto b = f[r - (1 << k) + 1][k];
        if (nums[a] > nums[b]) {
            return a;
        }
        return b;
    }

    TreeNode *build(int l, int r, const vector<vector<int>> &f, const vector<int> &nums) {
        if (l > r) {
            return nullptr;
        }
        auto k = query(l, r, f, nums);
        auto root = new TreeNode(nums[k]);
        root->left = build(l, k - 1, f, nums);
        root->right = build(k + 1, r, f, nums);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0654_H
