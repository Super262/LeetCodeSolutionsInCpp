//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0458_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0458_H

#include <cmath>

using namespace std;

class Solution {
    // 设k=minutesToTest/minutesToDie，我们最多可以给所有的x头猪喂k轮水
    // 每头猪有(k+1)种状态：0表示活着，k表示在第k轮喝水后死去。我们依次用编号为1～n的水喂编号为0～x-1的猪
    // 由x头猪的状态组成的(k+1)进制数的十进制表示即为有毒水桶的编号。因此(k+1)^x >= n，x=log(k+1,n)

public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        auto k = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(k + 1));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0458_H
