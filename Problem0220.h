//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0220_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0220_H

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        multiset<long> s;
        s.insert(2e10);
        s.insert(-2e10 - 1);  // 插入两个永不可达的边界值，简化查询操作
        for (int r = 0, l = 0; r < (int) nums.size(); ++r) {
            if (r - l > k) {
                s.erase(s.find(nums[l]));
                ++l;
            }
            auto x = nums[r];
            auto lt = s.lower_bound(x);  // element greater or equal
            if (*lt - x <= t) {  // 最接近x的较大元素
                return true;
            }
            --lt;
            if (x - *lt <= t) {  // 最接近x的较小元素
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0220_H
