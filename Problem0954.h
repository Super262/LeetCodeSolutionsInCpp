//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0954_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0954_H

#include <vector>
#include <map>

using namespace std;

class Solution {
    // 贪心构造：若x是arr中的最小数，若arr满足题意，2*x一定存在；正数和正数配对、零和零配对、负数和负数配对
    // 因此，我们每次尝试寻找x、2*x，并从arr中删去它们，直至集合为空
public:
    bool canReorderDoubled(const vector<int> &arr) {
        map<int, int> pos_nums;
        map<int, int> neg_nums;
        int pos_cnt = 0;  // 正数的个数
        int neg_cnt = 0;  // 负数的个数
        int zero_cnt = 0;  // 零的个数
        for (const auto &x: arr) {
            if (!x) {
                ++zero_cnt;
            } else if (x > 0) {
                pos_nums[x]++;
                ++pos_cnt;
            } else {
                neg_nums[-x]++;  // 为了让负数能从小输出，我们取其相反数
                ++neg_cnt;
            }
        }
        if (zero_cnt % 2 || pos_cnt % 2 || neg_cnt % 2) {  // 奇数个，无法配对
            return false;
        }
        return checkPair(pos_nums) && checkPair(neg_nums);
    }

private:
    static bool checkPair(map<int, int> &num_cnt) {
        while (!num_cnt.empty()) {
            auto it = num_cnt.begin();  // 当前最小值
            if (!it->second) {  // 无效值
                num_cnt.erase(it);
                continue;
            }
            auto x = it->first;
            if (!num_cnt.count(2 * x) || !num_cnt[2 * x]) {
                return false;
            }
            num_cnt[x]--;
            num_cnt[2 * x]--;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0954_H
