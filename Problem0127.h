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
public:
    int ladderLength(const string &beginWord,
                     const string &endWord,
                     const vector<string> &wordList) {
        unordered_set<string> words_set(wordList.begin(), wordList.end());
        words_set.insert(beginWord);
        if (!words_set.count(endWord)) {
            return 0;
        }
        unordered_map<string, int> dist;
        queue<string> q;
        dist[beginWord] = 1;
        q.emplace(beginWord);
        while (!q.empty()) {
            string root = q.front();
            q.pop();
            if (root == endWord) {
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
        if (!dist.count(endWord)) {
            return 0;
        }
        return dist[endWord];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0127_H
