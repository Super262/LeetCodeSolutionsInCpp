//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1028_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1028_H

#include <string>
#include <stack>
#include "treenode.h"

using namespace std;

class Problem1028 {
    // 先序遍历依照"根-左-右"的顺序访问节点，并且题目中规定了如果节点只有1个子节点，那么保证该子节点为左子节点
    // 因此，我们可以求出每个节点的深度，将它们和前驱节点相连，获得答案
public:
    TreeNode *recoverFromPreorder(const string &traversal) {
        int i = 0;
        stack<TreeNode *> s;
        while (i < (int) traversal.size()) {
            int level = 0;
            while (i < (int) traversal.size() && traversal[i] == '-') {
                ++i;
                ++level;
            }
            int val = 0;
            while (i < (int) traversal.size() && traversal[i] != '-') {
                val = val * 10 + (traversal[i] - '0');
                ++i;
            }
            auto node = new TreeNode(val);
            if (level == (int) s.size()) {
                if (!s.empty()) {
                    s.top()->left = node;
                }
            } else {
                while (s.size() > 1 && level != (int) s.size()) {
                    s.pop();
                }
                s.top()->right = node;
            }
            s.emplace(node);
        }
        while (s.size() > 1) {
            s.pop();
        }
        return s.top();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1028_H
