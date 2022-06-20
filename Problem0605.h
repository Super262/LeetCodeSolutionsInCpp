//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0605_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0605_H

#include <vector>

using namespace std;

class Solution {
    // 贪心思想：就近种植，若i可被种植，就在i种植
    // https://www.acwing.com/solution/content/469/
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        for (int i = 0; i < (int) flowerbed.size(); ++i) {
            if (flowerbed[i]) {
                continue;
            }
            if ((i == 0 || !flowerbed[i - 1]) && (i + 1 == (int) flowerbed.size() || !flowerbed[i + 1])) {
                --n;
                flowerbed[i] = 1;
                if (n <= 0) {
                    return true;
                }
            }
        }
        return n <= 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0605_H
