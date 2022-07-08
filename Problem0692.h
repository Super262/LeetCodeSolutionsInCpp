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
    // 首先，利用哈希表统计每个单词的频率；然后，我们遍历哈希表，将"(词频，单词)"压入大根堆；最后，弹出堆内前k个单词
    // 使用堆避免全排序，节约时间；make_heap()是线性时间构建堆；make_heap默认建立最大堆，注意自定义比较器的实现（相当于less）
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
        auto cmp = [&](const pair<int, string> &a, const pair<int, string> &b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        };
        make_heap(heap.begin(), heap.end(), cmp);
        vector<string> ans;
        ans.reserve(k);
        while (!heap.empty() && (int) ans.size() < k) {
            ans.emplace_back(heap[0].second);
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0692_H
