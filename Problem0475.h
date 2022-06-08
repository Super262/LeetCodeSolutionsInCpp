//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0475_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0475_H

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    // 二分答案：排序所有坐标，使房子、加热器的坐标单调递增；二分搜索半径R，再通过"双指针"判断R是否足够满足要求
    // 将房屋和暖气的位置分别从小到大排序；假设得到了加热半径R，即可在 O(n+m) 的时间内，判断是否所有的房屋都得到了暖气
    // 具体为，逐一枚举房屋，然后判断是否有暖气覆盖，由于房屋和暖气的坐标都是单调的，所以第i+1个房屋不会使用坐标小于第i个房屋的暖气位置
    // 加热半径R也是单调的，故可以使用二分来加速寻找最小的半径R
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0;
        int r = INT_MAX;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (checkRadius(mid, houses, heaters)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    bool checkRadius(int r, const vector<int> &houses, const vector<int> &heaters) {
        for (int i = 0, j = 0; i < (int) houses.size(); ++i) {
            while (j < (int) heaters.size() && abs(heaters[j] - houses[i]) > r) {
                ++j;
            }
            if (j >= (int) heaters.size()) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0475_H
