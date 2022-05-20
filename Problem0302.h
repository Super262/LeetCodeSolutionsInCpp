
//
// Created by Fengwei Zhang on 5/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0302_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0302_H

#include <vector>

using namespace std;

class Solution {
    // 最优解法：二分查找，时间复杂度为O(mlogn+nlogm)
    // 我们将黑色区域向x轴、y轴投影，投影具有如下性质：如果这里只有1个黑色区域，那么在投影后得到的1维数组中，所有黑色点是相连的
    // 我们将黑色点(x,y)投影到行数组和列数组，在[0,y]内二分查找左边界、在[y+1,n-1]内查找右边界、在[0,x]内查找上边界、在[x+1,m-1]内查找下边界
    // 技巧：函数作为参数传递（为简便，全为static）
public:
    int minArea(const vector<vector<char>> &image, int x, int y) {
        const auto m = (int) image.size();
        const auto n = (int) image[0].size();
        auto left = queryMin(image, 0, y, &colHasBlack);  // 查找最左侧的（索引最小）满足要求的列
        auto right = queryMax(image, y, n - 1, &colHasBlack);  // 查找最右侧的（索引最大）满足要求的列
        auto top = queryMin(image, 0, x, &rowHasBlack);  // 查找最上侧的（索引最小）满足要求的行
        auto bottom = queryMax(image, x, m - 1, &rowHasBlack);  // 查找最下侧的（索引最大）满足要求的行
        return (bottom - top + 1) * (right - left + 1);
    }

private:
    static int queryMin(const vector<vector<char>> &image,
                        int l,
                        int r,
                        bool (*check)(const vector<vector<char>> &, int)) {
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (check(image, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

    static int queryMax(const vector<vector<char>> &image,
                        int l,
                        int r,
                        bool (*check)(const vector<vector<char>> &, int)) {
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (check(image, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    static bool rowHasBlack(const vector<vector<char>> &image, int x) {
        for (const auto &ch: image[x]) {
            if (ch == '1') {
                return true;
            }
        }
        return false;
    }

    static bool colHasBlack(const vector<vector<char>> &image, int y) {
        for (const auto &row: image) {
            if (row[y] == '1') {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0302_H
