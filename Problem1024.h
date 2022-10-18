//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1024_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1024_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem1024 {
    // 贪心：按左端点排序，选择右端点最大的区间
public:
    int videoStitching(vector<vector<int>> &clips, int time) {
        sort(clips.begin(), clips.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int cur_end = 0;  // 当前的最右边界
        int ans = 0;
        for (int i = 0; i < (int) clips.size(); ++i) {
            if (clips[i][0] > cur_end) {  // 不连续，非法
                return -1;
            }
            auto j = i;
            auto next_end = clips[i][1];  // 探索可达的最右边界
            while (j + 1 < (int) clips.size() && clips[j + 1][0] <= cur_end) {
                next_end = max(next_end, clips[j + 1][1]);
                ++j;
            }
            cur_end = max(cur_end, next_end);
            ++ans;
            if (cur_end >= time) {
                return ans;
            }
            i = j;
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1024_H
