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
        vector<int> pointers(m, 0);
        vector<int> result(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int >>, greater<pair<
                long long, int>>> heap;

        int resTop = 0;
        result[resTop++] = 1;
        for (int i = 0; i < m; ++i) {
            heap.emplace(pair<long long, int>((long long) result[pointers[i]] * primes[i], i));
        }
        while (resTop < n) {
            auto t = heap.top();
            heap.pop();
            auto pIdx = t.second;
            if (t.first != result[resTop - 1]) {
                result[resTop++] = (int) t.first;
            }
            ++pointers[pIdx];
            heap.emplace(pair<long long, int>((long long) result[pointers[pIdx]] * primes[pIdx], pIdx));
        }

        return result[n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0313_H
