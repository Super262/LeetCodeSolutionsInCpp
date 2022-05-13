//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0127_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0127_H

#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    // BFS：根据各个单词间的关系，建立有向图（只保存dist，不保存边a->b）
public:
    int ladderLength(const string &begin_word,
                     const string &end_word,
                     const vector<string> &word_list) {
        unordered_set<string> words_set(word_list.begin(), word_list.end());
        words_set.insert(begin_word);
        if (!words_set.count(end_word)) {
            return 0;
        }
        unordered_map<string, int> dist;
        queue<string> q;
        dist[begin_word] = 1;
        q.emplace(begin_word);
        while (!q.empty()) {
            string root = q.front();
            q.pop();
            if (root == end_word) {
                break;
            }
            auto rd = dist[root];
            for (int i = 0; i < (int) root.size(); ++i) {
                auto t = root[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    root[i] = ch;
                    if (!words_set.count(root) || dist.count(root)) {
                        continue;
                    }
                    dist[root] = rd + 1;
                    q.emplace(root);
                }
                root[i] = t;
            }
        }
        if (!dist.count(end_word)) {
            return 0;
        }
        return dist[end_word];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0127_H
