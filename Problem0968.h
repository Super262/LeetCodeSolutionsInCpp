//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0968_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0968_H

#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 树形DP：参考AcWing1077-皇宫看守
    // f[u][s]：s=0，u被它的父节点照看；s=1，u被它的子节点照看；s=2，u被自己照看
public:
    int minCameraCover(TreeNode *root) {
        auto ans = dp(root);
        return min(ans.s1, ans.s2);
    }

private:
    struct Tuple {
        int s0;
        int s1;
        int s2;
    };

    Tuple dp(TreeNode *root) {
        if (!root) {  // 空节点，无法照看自己
            return {0, 0, 0x3f3f3f3f};
        }
        Tuple ans{0, 0x3f3f3f3f, 1};  // 初始值

        auto lt = dp(root->left);
        auto rt = dp(root->right);

        auto kids_cost = min(lt.s1, lt.s2) + min(rt.s1, rt.s2);

        ans.s0 += kids_cost;

        ans.s2 += min(lt.s0, min(lt.s1, lt.s2)) + min(rt.s0, min(rt.s1, rt.s2));

        ans.s1 = min(ans.s1, kids_cost - min(lt.s1, lt.s2) + lt.s2);
        ans.s1 = min(ans.s1, kids_cost - min(rt.s1, rt.s2) + rt.s2);

        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0968_H
