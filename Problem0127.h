//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0127_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0127_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Problem0127 {
public:
    int ladderLength(const string &beginWord,
                     const string &endWord,
                     const vector<string> &wordList) {
        unordered_set<string> wordsSet;
        unordered_map<string, int> dist;
        queue <string> q;
        for (const auto &s: wordList) {
            wordsSet.insert(s);
        }
        wordsSet.insert(beginWord);
        vector<vector<string>> result;
        if (!wordsSet.count(endWord)) {
            return 0;
        }
        dist[beginWord] = 1;
        q.emplace(beginWord);
        while (!q.empty()) {
            const auto root = q.front();
            q.pop();
            if (root == endWord) {
                break;
            }
            for (int i = 0; i < (int) root.size(); ++i) {
                auto temp = root;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    temp[i] = ch;
                    if (!wordsSet.count(temp) || dist.count(temp)) {
                        continue;
                    }
                    dist[temp] = dist[root] + 1;
                    q.emplace(temp);
                }
            }
        }
        if (!dist.count(endWord)) {
            return 0;
        }
        return dist[endWord];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0127_H
