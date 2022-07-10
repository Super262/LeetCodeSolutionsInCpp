//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0559_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0559_H

#include <vector>
#include "node_nary.h"

using namespace std;

class Solution {
    // 类似后序遍历，先处理子节点，获得子节点的最大深度d，根结点深度为d+1
public:
    int maxDepth(Node *root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        for (const auto &t: root->children) {
            res = max(res, maxDepth(t));
        }
        return res + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0559_H
