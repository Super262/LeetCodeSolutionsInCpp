//
// Created by Fengwei Zhang on 6/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0544_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0544_H

#include <string>
#include <deque>

using namespace std;

class Solution {
    // 直接模拟：设上回合比赛的队列为q，本回合比赛的队列为nq，我们发现nq的首项由q的首项、尾项组合而成
    // 若q=[a,b,c,d]，那么nq=[(a,d),(b,c)]；我们根据这个性质模拟整个过程，直到队列中只有1个元素
    // 最优做法：线性输出（https://leetcode.cn/problems/output-contest-matches/solution/shu-chu-bi-sai-pi-pei-dui-by-leetcode/）
public:
    string findContestMatch(int n) {  // 直接模拟
        deque<string> q;
        for (int i = 1; i <= n; ++i) {
            q.emplace_back(to_string(i));
        }
        while (q.size() > 1) {
            auto k = (int) q.size();
            deque<string> nq;
            for (int i = 0; i < k; i += 2) {
                auto a = q.front();
                q.pop_front();
                auto b = q.back();
                q.pop_back();
                nq.emplace_back('(' + a + ',' + b + ')');
            }
            q = nq;
        }
        return q.front();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0544_H
