//
// Created by Fengwei Zhang on 4/11/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0911_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0911_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TopVotedCandidate {
    // 预处理出每一时刻的赢家；根据查询的输入，二分查找满足要求的时刻
public:
    TopVotedCandidate(const vector<int> &persons, const vector<int> &times) {
        unordered_map<int, int> cnt;
        this->times = times;
        winner.resize(this->times.size());
        int maxc = 0;
        int maxp = -1;
        for (int i = 0; i < (int) this->times.size(); ++i) {
            cnt[persons[i]]++;
            if (cnt[persons[i]] >= maxc) {  // 票数相同时，最近获选的获胜
                maxc = cnt[persons[i]];
                maxp = persons[i];
            }
            winner[i] = maxp;
        }
    }

    int q(int t) {
        auto k = (int) (upper_bound(times.begin(), times.end(), t) - times.begin() - 1);
        return winner[k];
    }

private:
    vector<int> times;
    vector<int> winner;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0911_H
