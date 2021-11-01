//
// Created by Fengwei Zhang on 10/31/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0095_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0095_H

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0095 {
public:
    vector<TreeNode *> generateTrees(const int &n) {
        return dfs(1, n);
    }

    vector<TreeNode *> dfs(const int &l, const int &r) {
        vector<TreeNode *> res;
        if (l > r) {
            res.emplace_back(nullptr);
        }
        for (int rootIdx = l; rootIdx <= r; ++rootIdx) {
            auto leftKids = dfs(l, rootIdx - 1);
            auto rightKids = dfs(rootIdx + 1, r);
            for (auto lk: leftKids) {
                for (auto rk: rightKids) {
                    res.emplace_back(new TreeNode(rootIdx, lk, rk));
                }
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0095_H
