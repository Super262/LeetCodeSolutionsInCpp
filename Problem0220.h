//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0220_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0220_H

#include <vector>
#include <set>

using namespace std;

class Problem0220 {
private:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        multiset<long long> S;
        S.insert(2e10);
        S.insert(-2e10 - 1);  // 插入两个永不可达的边界值，简化查询操作
        for (unsigned long long i = 0, j = 0; i < nums.size(); ++i) {
            if (i - j > k) {
                S.erase(S.find(nums[j++]));
            }
            auto x = nums[i];
            auto lt = S.lower_bound(x);  // element greater or equal
            if (*lt - x <= t) {  // 最接近x的较大元素
                return true;
            }
            --lt;
            if (x - *lt <= t) {  // 最接近x的较小元素
                return true;
            }
            S.insert(x);
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0220_H
