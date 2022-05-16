//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0251_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0251_H

#include <vector>

using namespace std;

class Vector2D {
    // 注意细节，列迭代器走到尾部后，更新行迭代器，直至数组尾部
private:
    vector<vector<int>>::iterator row_it;  // 当前行
    vector<int>::iterator col_it;  // 当前列
    vector<vector<int>>::iterator grid_end;  // 矩阵尾部

public:
    Vector2D(vector<vector<int>> &vec) {
        grid_end = vec.end();
        row_it = vec.begin();
        while (row_it != grid_end && row_it->empty()) {  // 跳过空行，寻找第一个有效元素
            row_it++;
        }
        if (row_it != grid_end) {
            col_it = row_it->begin();
        }
    }

    int next() {
        auto ans = *col_it;
        col_it++;
        while (row_it != grid_end && col_it == row_it->end()) {  // 寻找下一个有效元素
            row_it++;
            if (row_it != grid_end) {
                col_it = row_it->begin();
            }
        }
        return ans;
    }

    bool hasNext() {
        return row_it != grid_end;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0251_H
