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
        const auto m = (int) primes.size();
        vector<int> pointers(m, 0);  // primes[i] * res[pointers[i]] 是未来的"丑数"
        vector<int> res;
        // 小根堆，保存{prime * factor, prime_index}
        priority_queue<pair<long long, int>, vector<pair<long long, int >>, greater<pair<long long, int>>> heap;
        res.reserve(n);
        res.emplace_back(1);
        for (int i = 0; i < m; ++i) {  // 初始化
            heap.push({(long long) res[pointers[i]] * primes[i], i});
        }
        while (res.size() < n) {
            auto t = heap.top();  // 当前最小值
            heap.pop();
            auto p_idx = t.second;
            if (t.first != res.back()) {  // 注意：别忘记判重，result中不能包括重复元素
                res.emplace_back((int) t.first);
            }
            ++pointers[p_idx];  // 下一个底数
            heap.push({(long long) res[pointers[p_idx]] * primes[p_idx], p_idx});  // 插入下一个运算结果
        }
        return res[n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0313_H
