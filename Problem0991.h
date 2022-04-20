//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0991_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0991_H

class Solution {
    // 若我们希望从y达到(y+k)/2，我们有以下2条路径可选：
    // （1）y -> y + k -> (y + k) / 2；（2）y -> y / 2 -> y / 2 + k / 2；显然，第2条路径的操作次数更少
    // 我们逆向思考原题，设初始值是x，目标值是y，考虑由y到x的过程：若y为偶数，则y/=2；若y为奇数，为了尽可能执行"减半操作"，y++
public:
    int brokenCalc(int start, int target) {
        int ans = 0;
        while (target > start) {
            if (target % 2) {
                ++target;
            } else {
                target /= 2;
            }
            ++ans;
        }
        return ans + (start - target);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0991_H
