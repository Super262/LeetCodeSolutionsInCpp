//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0927_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0927_H

#include <vector>
#include <numeric>

using namespace std;

class Solution {
    // 设arr中"1"的个数为sum，avg = sum / 3；在等分后的每段中，设子数组[i,j]为包含全部"1"的最短段，且arr[i] == arr[j] == 1成立
    // [i:j]段所含"1"的个数应为avg；设[i:j]段后零的个数为tail_zeros；在等分后，每段[i:j]部分含"1"的个数相等、tail_zeros相等
public:
    vector<int> threeEqualParts(const vector<int> &arr) {
        auto sum = accumulate(arr.begin(), arr.end(), 0);
        if (!sum) {
            return {0, 2};
        }
        if (sum % 3) {
            return {-1, -1};
        }
        const auto avg = sum / 3;
        int p[6];  // 3个[i:j]段的索引
        // 每个[i:j]段起点和终点对应的"1"的计数
        int s[6] = {1, avg, avg + 1, 2 * avg, 2 * avg + 1, 3 * avg};
        for (int i = 0, j = 0, cnt = 0; i < (int) arr.size(); ++i) {
            if (!arr[i]) {
                continue;
            }
            ++cnt;
            while (j < 6 && cnt == s[j]) {  // 注意：若avg为1，当cnt等于1时，多个p[j]都应被赋值
                p[j] = i;
                ++j;
            }
        }
        auto tail_zeros = (int) arr.size() - 1 - p[5];
        if (p[2] - p[1] - 1 < tail_zeros || p[4] - p[3] - 1 < tail_zeros) {  // 前2段尾部"0"的个数太少
            return {-1, -1};
        }
        if (!arrEqual(arr, p[0], p[1] + tail_zeros, p[2], p[3] + tail_zeros)) {
            return {-1, -1};
        }
        if (!arrEqual(arr, p[2], p[3] + tail_zeros, p[4], p[5] + tail_zeros)) {
            return {-1, -1};
        }
        return {p[1] + tail_zeros, p[3] + tail_zeros + 1};
    }

private:
    bool arrEqual(const vector<int> &arr, int s1, int e1, int s2, int e2) {
        for (auto i = s1, j = s2; i <= e1 && j <= e2; ++i, ++j) {
            if (arr[i] != arr[j]) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0927_H
