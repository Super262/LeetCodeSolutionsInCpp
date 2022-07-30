//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0766_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0766_H

#include <vector>

using namespace std;

class Problem0766 {
    // 逐个验证每个对角线
    // 进阶一：我们将每一行复制到一个连续数组中，随后在读取下一行时，就与内存中此前保存的数组进行比较
    // 进阶二：我们将整个矩阵竖直切分成若干子矩阵，并保证两个相邻的矩阵至少有一列或一行是重合的，然后判断每个子矩阵是否符合要求
public:
    bool isToeplitzMatrix(const vector<vector<int>> &matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0766_H
