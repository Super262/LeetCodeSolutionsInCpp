//
// Created by Fengwei Zhang on 6/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0573_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0573_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 根据题意，松鼠s最多携带1个坚果；当松鼠s将第1颗坚果藏到树t后，松鼠s会往返于树t和其它坚果nuts间
    // 设松鼠s第1次选择的坚果是i，答案是min({2*sum({getDist(t,nut) for nut int nuts})+getDist(s,nuts[i])-getDist(t,nuts[i])})
public:
    int minDistance(int m, int n, const vector<int> &t, const vector<int> &squirrel, const vector<vector<int>> &nuts) {
        int dist_sum = 0;
        for (const auto &nut: nuts) {
            dist_sum += 2 * getDist(nut, t);
        }
        int ans = INT_MAX;
        for (const auto &first: nuts) {
            ans = min(ans, dist_sum + getDist(squirrel, first) - getDist(first, t));
        }
        return ans;
    }

private:
    int getDist(const vector<int> &a, const vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0573_H
