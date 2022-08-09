//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0805_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0805_H

#include <vector>
#include <set>
#include <numeric>

using namespace std;

class Problem0805 {
    // 经观察，若A、B的平均值相等，说明A、B的平均值都等于数组nums的平均值avg；那么若A满足题意，B就满足题意，反之亦然
    // 初步想法：设数组nums长度是n，枚举状态s（n位二进制数，0<=s<(1<<n)）；若s[i]=0，将nums[i]加入A，否则将nums[i]加入B；最后验证A、B
    // 上述方法的时间复杂度是O(2^n)，会超时；我们采取折半枚举（AcWing 163）：设m=n/2，s表示这m个数的状态；集合sum_set保存{sum, cnt}
    // sum是当前被选中的数字的和，cnt是当前被选中的数字的个数；枚举完前m个数字后，枚举剩余的(n-m)个数字；设cnt是枚举剩余(n-m)个数字时选中的数字的个数
    // sum是枚举剩余(n-m)个数字时选中的数字的和；若在枚举前m个数字生成的结果集sum_set中存在{c*avg-sum,c-cnt}，返回true（cnt<=c<n，表示A或B的长度）
public:
    bool splitArraySameAverage(const vector<int> &nums) {
        const auto n = (int) nums.size();
        const auto m = n / 2;
        // 设状态为1的数字会被加入到A
        set<pair<int, int>> sum_set;
        for (int s = 0; s < (1 << m); ++s) {  // 枚举前m个数，选出在A的部分
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if ((s >> i) & 1) {
                    ++cnt;
                    sum += nums[i];
                }
            }
            sum_set.insert({sum, cnt});
        }
        auto all_sum = accumulate(nums.begin(), nums.end(), 0);
        for (int s = 0; s < (1 << (n - m)); ++s) {  // 枚举剩余的(n-m)个数，选出在A的部分
            int sum = 0;
            int cnt = 0;
            for (int i = m; i < n; ++i) {
                if ((s >> (i - m)) & 1) {
                    ++cnt;
                    sum += nums[i];
                }
            }
            for (auto c = max(1, cnt); c < n; ++c) {
                if (c * all_sum % n) {  // 无法整除，avg*c无效
                    continue;
                }
                auto t = c * all_sum / n;  // 当前数组的总和
                pair<int, int> left = {t - sum, c - cnt};
                if (sum_set.find(left) != sum_set.end()) {  // 说明A存在
                    return true;
                }
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0805_H
