//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0501_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0501_H

#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似中序遍历，递归过程中更新全局变量
public:
    vector<int> findMode(TreeNode *root) {
        vector<int> modes;
        int mode_freq = 0;
        int cur_val;
        int cur_freq = 0;
        inOrder(root, cur_val, cur_freq, modes, mode_freq);
        return modes;
    }

private:
    void inOrder(TreeNode *root, int &cur_val, int &cur_freq, vector<int> &modes, int &mode_freq) {
        if (!root) {
            return;
        }
        inOrder(root->left, cur_val, cur_freq, modes, mode_freq);
        auto x = root->val;
        if (!cur_freq || cur_val != x) {
            cur_freq = 1;
            cur_val = x;
        } else {
            ++cur_freq;
        }
        if (cur_freq > mode_freq) {
            modes.clear();
            mode_freq = cur_freq;
            modes.emplace_back(cur_val);
        } else if (cur_freq == mode_freq) {
            modes.emplace_back(cur_val);
        }
        inOrder(root->right, cur_val, cur_freq, modes, mode_freq);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0501_H
