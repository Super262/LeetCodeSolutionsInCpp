
//
// Created by Fengwei Zhang on 5/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0358_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0358_H

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
    // 我们应先把出现次数最多的字符先放完；用长度为k的滑动窗口（队列）保存候选字符，保证当前位置和上个和队头相等的元素的距离不少于k
    // 优先队列按字符频率从大到小保存字符，弹出堆顶字符ch后，将字符ch加入结果集，频率减1，ch入队列
    // 细节：我们要跳过频率为0的队头元素
public:
    string rearrangeString(const string &s, int k) {
        unordered_map<char, int> counter;
        for (const auto &ch: s) {
            counter[ch]++;
        }
        priority_queue<pair<int, char>> heap;
        for (const auto &item: counter) {
            heap.emplace(item.second, item.first);
        }
        string ans;
        queue<pair<int, char>> q;
        while (!heap.empty()) {
            auto p = heap.top();
            heap.pop();
            ans += p.second;
            q.emplace(p.first - 1, p.second);
            if (q.size() < k) {  // 间距不足k
                continue;
            }
            auto t = q.front();
            q.pop();
            if (t.first <= 0) {  // 候选元素不存在，跳过
                continue;
            }
            heap.emplace(t);
        }
        while (!q.empty() && q.front().first <= 0) {
            q.pop();
        }
        return q.empty() ? ans : "";  // 若还有候选元素，答案无效
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0358_H
