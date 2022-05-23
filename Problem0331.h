//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0331_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0331_H

#include <string>

using namespace std;

class Solution {
    // 将输入序列看作二叉树，先处理根结点，再处理左右子树，每次只处理一个节点
    // 为简化处理，我们在输入序列的尾部补充分隔符"，"
public:
    bool isValidSerialization(string preorder) {
        preorder.push_back(',');  // 添加分隔符，标识结尾
        int idx = 0;
        if (!dfs(preorder, idx)) {
            return false;
        }
        return idx == (int) preorder.size();
    }

private:
    bool dfs(const string &s, int &idx) {
        if (idx == (int) s.size()) {  // 未开始搜索就到达结尾
            return false;
        }
        if (s[idx] == '#') {
            idx += 2;  // 跳过‘#’和分隔符
            return true;
        }
        while (s[idx] != ',') {  // 跳过当前节点和分隔符
            ++idx;
        }
        ++idx;
        return dfs(s, idx) && dfs(s, idx);  // 分别确认左子树和右子树
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0331_H
