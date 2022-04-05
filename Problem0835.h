//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0835_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0835_H

#include <vector>

using namespace std;

class Solution {
    // 每种情况从第一个矩阵的某个角开始，遍历两个矩阵的公共部分并统计更新答案
    // 枚举相交部分的长宽
public:
    int largestOverlap(const vector<vector<int>> &img1, const vector<vector<int>> &img2) {
        const auto n = (int) img1.size();
        int ans = 0;
        for (int dx = 1; dx <= n; ++dx) {
            for (int dy = 1; dy <= n; ++dy) {
                int cnt1 = 0;  // img1右下角、img2左上角
                int cnt2 = 0;  // img1左下角、img2右上角
                int cnt3 = 0;  // img1左上角、img2右下角
                int cnt4 = 0;  // img1右上角、img2左下角
                for (int i = 0; i < dx; ++i) {
                    for (int j = 0; j < dy; ++j) {
                        if (img1[n - dx + i][n - dy + j] && img2[i][j]) {
                            ++cnt1;
                        }
                        if (img1[n - dx + i][j] && img2[i][n - dy + j]) {
                            ++cnt2;
                        }
                        if (img1[i][j] && img2[n - dx + i][n - dy + j]) {
                            ++cnt3;
                        }
                        if (img1[i][n - dy + j] && img2[n - dx + i][j]) {
                            ++cnt4;
                        }
                    }
                }
                ans = max(ans, cnt1);
                ans = max(ans, cnt2);
                ans = max(ans, cnt3);
                ans = max(ans, cnt4);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0835_H
