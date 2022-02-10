//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0654_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0654_H

#include <vector>
#include <cmath>

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
    // 经典算法，必须掌握：RMQ
public:
    TreeNode *constructMaximumBinaryTree(const vector<int> &nums) {
        const auto n = (int) nums.size();
        const auto k = (int) (log(n) / log(2));
        vector<vector<int>> f(n, vector<int>(k + 1, 0));
        for (int j = 0; j <= k; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                if (!j) {
                    f[i][j] = i;
                } else {
                    auto l = f[i][j - 1];
                    auto r = f[i + (1 << (j - 1))][j - 1];
                    if (nums[l] > nums[r]) {
                        f[i][j] = l;
                    } else {
                        f[i][j] = r;
                    }
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
