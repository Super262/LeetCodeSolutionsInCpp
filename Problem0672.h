//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0672_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0672_H

#include <algorithm>

using namespace std;

class Solution {
    // 首先，我们发现这n盏灯的结束状态是以周期k=6分布的；选取第i盏灯，第i盏灯和第i+6盏灯的状态相同（加6不改变奇偶性，也不改变"模3"的结果）
    // 我们发现前3个灯泡可以决定所有灯泡的状态；假设操作1执行了a次、操作2执行了b次、操作3执行了c次、操作4执行了d次
    // 灯泡1的状态为(1+a+c+d)%2，灯泡2的状态为(1+a+b)%2，灯泡3的状态为(1+a+c)%2，灯泡4的状态为(1+a+b+d)%2
    // 灯泡5和灯泡3的状态相等；灯泡6和灯泡2的状态相等；灯泡7和灯泡1状态相等；以此类推，前3个灯泡可以决定所有灯泡的状态
    // 因此，若灯泡1和灯泡3相等，说明d是偶数，那么灯泡2也等于灯泡4；若灯泡1和灯泡3不相等，说明d是奇数，那么灯泡2也不等于灯泡4
public:
    int flipLights(int n, const int m) {
        n = min(n, 3);
        if (m == 0) {
            return 1;
        }
        if (m == 1) {
            int s[3] = {2, 3, 4};
            return s[n - 1];
        }
        if (m == 2) {
            int s[3] = {2, 4, 7};
            return s[n - 1];
        }
        int s[3] = {2, 4, 8};
        return s[n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0672_H
