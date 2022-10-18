//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1018_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1018_H

#include <vector>

using namespace std;

class Problem1018 {
    // 由于nums可能长达100000，我们不可能将nums所代表的二进制数字完整记录下来。我们只关心前缀除5的余数，因此我们只保存余数信息
    // cur = Binary(nums[0:i]) % 5
public:
    vector<bool> prefixesDivBy5(const vector<int> &nums) {
        vector<bool> ans(nums.size(), false);
        int cur = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            cur = (cur * 2 + nums[i]) % 5;
            if (cur % 5) {
                continue;
            }
            ans[i] = true;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1018_H
