//
// Created by Fengwei Zhang on 5/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0272_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0272_H

#include <vector>
#include <queue>
#include "treenode.h"

using namespace std;

class Solution {
    // O(n)时间解法：利用BST中序序列的有序性，将遍历过的点存入队列
    // 队头是距离target最远的点，若当前点比队头更远，则终止遍历；否则，弹出队头，压入当前点
public:
    vector<int> closestKValues(TreeNode *root, double target, int k) {
        queue<int> q;
        inOrder(root, q, target, k);
        vector<int> ans;
        ans.reserve(q.size());
        while (!q.empty()) {
            ans.emplace_back(q.front());
            q.pop();
        }
        return ans;
    }

private:
    void inOrder(TreeNode *root, queue<int> &q, double target, int k) {
        if (!root) {
            return;
        }
        inOrder(root->left, q, target, k);
        if (q.size() == k) {
            auto x = q.front();
            if (abs(target - x) <= abs(target - root->val)) {
                return;
            }
            q.pop();
        }
        q.emplace(root->val);
        inOrder(root->right, q, target, k);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0272_H
