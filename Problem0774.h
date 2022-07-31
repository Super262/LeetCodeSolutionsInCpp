//
// Created by Fengwei Zhang on 7/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0774_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0774_H

#include <vector>

using namespace std;

class Problem0774 {
    // 二分查找，逆向思维：搜索最小的d，满足相邻station间距离小于d时，需添加的station的数量不超过k
    // 若要使两个station间分段的距离小于d，则应加入floor((station[i+1]-station[i])/d)个station
public:
    double minmaxGasDist(const vector<int> &stations, int k) {
        double l = 0;
        double r = 1e8;
        while (abs(l - r) > 1e-6) {
            auto mid = l + (r - l) / 2;
            if (check(stations, k, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }

private:
    bool check(const vector<int> &stations, int k, double d) {
        int cnt = 0;
        for (int i = 0; i < (int) stations.size() - 1; ++i) {
            cnt += (int) ((stations[i + 1] - stations[i]) / d);
        }
        return cnt <= k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0774_H
