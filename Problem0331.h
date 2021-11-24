//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0331_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0331_H

#include <string>

using namespace std;

class Solution {
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
        while (s[idx] != ',') {
            ++idx;
        }
        ++idx;
        return dfs(s, idx) && dfs(s, idx);  // 分别确认左子树和右子树
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0331_H
