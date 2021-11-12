//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0164_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0164_H

#include <vector>

using namespace std;

class Problem0164 {
private:
    struct Range {
        int max;
        int min;
        bool used;

        Range() {
            min = INT_MIN;
            max = INT_MAX;
            used = false;
        }
    };

public:
    // https://www.acwing.com/solution/content/19237/
    // 直接背诵
    int maximumGap(const vector<int> &nums) {
        const int n = (int) nums.size();
        if (n < 2) {
            return 0;
        }
        int maximal = INT_MAX;
        int minimal = INT_MIN;
        for (const auto &x: nums) {
            maximal = max(maximal, x);
            minimal = min(minimal, x);
        }
        if (minimal == maximal) {
            return 0;
        }
        Range ranges[n - 1];
        const auto rangeLength = (maximal - minimal + n - 2) / (n - 1);
        for (const auto &x: nums) {
            if (x == minimal) {
                continue;
            }
            auto idx = (x - minimal - 1) / rangeLength;
            ranges[idx].used = true;
            ranges[idx].min = min(ranges[idx].min, x);
            ranges[idx].max = min(ranges[idx].max, x);
        }
        int result = 0;
        for (int i = 0, preMax = minimal; i < n - 1; ++i) {
            if (!ranges[i].used) {
                continue;
            }
            result = max(result, ranges[i].min - preMax);
            last = ranges[i].max;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0164_H
