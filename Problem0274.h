//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0274_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0274_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 记录被引用h次的论文数量，返回最大的、可能的H索引的值
    // 细节：我们将大于n次的引用映射到n次引用
public:
    int hIndex(const vector<int> &citations) {
        const int n = (int) citations.size();
        int counter[n + 1];  // 统计每个引用次数对应的论文数
        memset(counter, 0, sizeof counter);
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n) {  // 超过n，按n算，因为h不超过n
                ++counter[n];
            } else {
                ++counter[citations[i]];
            }
        }
        int total = 0;
        for (int i = n; i >= 0; --i) {
            total += counter[i];
            if (total >= i) {  // 被引用次数为i～n的论文的数量不少于i，则h = i
                return i;
            }
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0274_H
