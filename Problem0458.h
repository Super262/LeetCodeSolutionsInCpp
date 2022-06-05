//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0458_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0458_H

#include <cmath>

using namespace std;

class Solution {
    // 设k=minutesToTest/minutesToDie，我们最多可以给所有的x头猪喂k轮水
    // 由x头猪的状态组成的(k+1)进制数是最大的信息量。我们应使(k+1)^x >= n，x=log(k+1,n)
    // 那么，如何利用这最大的信息量，举例：https://leetcode.cn/problems/poor-pigs/solution/hua-jie-suan-fa-458-ke-lian-de-xiao-zhu-by-guanpen/
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        auto k = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(k + 1));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0458_H
