//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0313_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0313_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(const int &n, const vector<int> &primes) {
        const int m = (int) primes.size();
        vector<int> pointers(m, 0);  // 保存每个质数因子对应result中底数的索引
        vector<int> result(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int >>, greater<pair<
                long long, int>>> heap;  // 小根堆，保存{prime * factor, prime_index}
        int resTop = 0;
        result[resTop++] = 1;
        for (int i = 0; i < m; ++i) {  // 初始化
            heap.emplace(pair<long long, int>((long long) result[pointers[i]] * primes[i], i));
        }
        while (resTop < n) {
            auto t = heap.top();  // 当前最小值
            heap.pop();
            auto pIdx = t.second;
            if (t.first != result[resTop - 1]) {  // 注意：别忘记判重，result中不能包括重复元素
                result[resTop++] = (int) t.first;
            }
            ++pointers[pIdx];  // 下一个底数
            heap.emplace(pair<long long, int>((long long) result[pointers[pIdx]] * primes[pIdx], pIdx));  // 插入下一个运算结果
        }
        return result[n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0313_H
