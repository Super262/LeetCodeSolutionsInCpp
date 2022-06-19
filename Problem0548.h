//
// Created by Fengwei Zhang on 6/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0548_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0548_H

#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

class Solution {
    // 前缀和+哈希表；根据题意，我们要找到一组i、j、k，满足sum(nums[0:i-1])=sum(nums[i+1:j-1])=sum(nums[j+1:k-1])=sum(nums[k+1:n-1])
    // 若暴力枚举3个指针的位置，会超时；我们观察到，若j的位置一定，那么i、k的活动区间就确定了；因此我们可以固定j，预存所有sum(nums[0:i-1])=sum(nums[i+1:j-1])到哈希表
    // 再枚举k的位置，去哈希表查询是否存在t=sum(nums[j+1:k-1])=sum(nums[k+1:n-1])
public:
    bool splitArray(const vector<int> &nums) {
        if (nums.size() < 7) {
            return false;
        }
        const auto n = (int) nums.size();
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        unordered_set<int> sum_set;
        for (int j = 3; j < n - 3; ++j) {
            sum_set.clear();  // 清空集合
            for (int i = 1; i < j - 1; ++i) {  // 预存sum(nums[0:i-1])=sum(nums[i+1:j-1])
                if (prefix[i] - prefix[0] == prefix[j] - prefix[i + 1]) {
                    sum_set.insert(prefix[i] - prefix[0]);
                }
            }
            for (int k = j + 2; k < n - 1; ++k) {  // 查询是否存在t=sum(nums[j+1:k-1])=sum(nums[k+1:n-1])
                if (prefix[k] - prefix[j + 1] == prefix[n] - prefix[k + 1] &&
                    sum_set.count(prefix[k] - prefix[j + 1])) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0548_H
