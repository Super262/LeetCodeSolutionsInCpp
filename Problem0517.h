//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0517_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0517_H

#include <vector>
#include <numeric>

using namespace std;

class Solution {
    // 贪心算法：由于每台洗衣机在每次操作中只能运送1次衣服（向左或向右），若最终每台洗衣机有avg件衣服，必然有某个洗衣机在某次操作中运送了avg件衣服
    // 若不存在一个洗衣机，它运送的衣服数量等于答案，则必定是这种情况：洗衣机A运送了一次，洗衣机B不动；然后洗衣机B运送了一次，洗衣机A不动；但这种情况显然可以并行完成
    // 因此，我们可以枚举每一台洗衣机，计算经过它运送的衣服的数量；设当前洗衣机的编号是i，left_sum=sum(machines[0:i-1])，right_sum=sum(machines[i+1:n-1])
    // 故需要经过这台洗衣机从右向左运送的衣服数量为r_to_l=i*avg-left_sum；从左向右运行的衣服数量l_to_r同理
    // r_2_l+l_2_r就是这台洗衣机的工作量，对每一台洗衣机都这样求和得到工作量，取工作量最大的洗衣机就是答案
    // https://www.acwing.com/solution/content/413/
public:
    int findMinMoves(const vector<int> &machines) {
        const auto total = accumulate(machines.begin(), machines.end(), 0);
        const auto n = (int) machines.size();
        if (total % n) {  // 无法均分衣服，直接返回
            return -1;
        }
        const auto avg = total / n;
        int answer = 0;
        int left_sum = 0;
        int right_sum = total;
        for (int i = 0; i < n; ++i) {
            right_sum -= machines[i];
            auto r_to_l = max(0, i * avg - left_sum);
            auto l_to_r = max(0, (n - i - 1) * avg - right_sum);
            answer = max(answer, r_to_l + l_to_r);
            left_sum += machines[i];
        }
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0517_H
