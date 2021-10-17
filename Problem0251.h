//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0251_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0251_H

#include <vector>

using namespace std;

class Vector2D {
private:
    vector<vector<int>>::iterator rowIt;
    vector<int>::iterator colIt;
    vector<vector<int>>::iterator vecEnd;

public:
    Vector2D(vector<vector<int>> &vec) {
        vec.emplace(vec.begin(), vector<int>({-1}));  // 添加一个无效的头节点
        rowIt = vec.begin();
        colIt = rowIt->begin();
        vecEnd = vec.end();
    }

    int next() {
        ++colIt;
        while (colIt == rowIt->end()) {
            ++rowIt;
            colIt = rowIt->begin();
        }
        return *colIt;
    }

    bool hasNext() {
        auto tempCol = colIt;
        auto tempRow = rowIt;
        ++tempCol;
        while (tempRow != vecEnd && tempCol == tempRow->end()) {
            ++tempRow;
            if (tempRow != vecEnd) {
                tempCol = tempRow->begin();
            }
        }
        if (tempRow != vecEnd && tempCol != tempRow->end()) {
            return true;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0251_H
