//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0124_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0124_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 经典算法，直接背诵
    // https://www.acwing.com/solution/content/215/
public:
    int maxPathSum(TreeNode *root) {
        int answer = -0x3f3f3f3f;
        dfs(root, answer);
        return answer;
    }

private:
    int dfs(TreeNode *root, int &answer) {
        if (!root) {
            return 0;
        }
        auto ls = max(0, dfs(root->left, answer));  // ls、rs的下限是0！
        auto rs = max(0, dfs(root->right, answer));
        answer = max(answer, ls + rs + root->val);
        return max(ls, rs) + root->val;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0124_H
