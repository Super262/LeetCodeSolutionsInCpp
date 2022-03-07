//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0692_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0692_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    // 使用堆避免全排序，节约时间；线性时间构建堆
public:
    vector<string> topKFrequent(const vector<string> &words, int k) {
        unordered_map<string, int> counter;
        for (const auto &s: words) {
            ++counter[s];
        }
        vector<pair<int, string>> heap;
        heap.reserve(counter.size());
        for (const auto &item: counter) {
            heap.emplace_back(item.second, item.first);
        }
        auto cmp = [](const pair<int, string> &a, const pair<int, string> &b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        };
        make_heap(heap.begin(), heap.end(), cmp);  // make_heap默认建立最大堆，注意自定义比较器的实现（相当于less）
        vector<string> res;
        res.reserve(k);
        while (k--) {
            res.emplace_back(heap[0].second);
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0692_H
