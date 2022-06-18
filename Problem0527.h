//
// Created by Fengwei Zhang on 6/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0527_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0527_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordsAbbreviation(const vector<string> &words) {
        unordered_map<string, vector<int>> abbr_words;
        for (int i = 0; i < (int) words.size(); ++i) {
            abbr_words[abbreviate(words[i], 0)].emplace_back(i);
        }
        vector<string> ans(words.size());
        for (const auto &item: abbr_words) {
            auto root = new Node();
            for (const auto &i: item.second) {
                insertWord(root, words[i]);
            }
            for (const auto &i: item.second) {
                auto j = findLeaf(root, words[i]);
                if (j == -1) {
                    return {};
                }
                ans[i] = abbreviate(words[i], j);
            }
        }
        return ans;
    }

private:
    struct Node {
        int cnt;
        Node *children[26]{};

        Node() {
            cnt = 0;
            for (auto &kid: children) {
                kid = nullptr;
            }
        }
    };

    string abbreviate(const string &s, int i) {  // 将s缩写为s[0:i]+"n-i-2"+s[n-1]，满足题目的"较长前缀"要求
        if (s.size() - i - 2 <= 1) {
            return s;
        }
        return s.substr(0, i + 1) + to_string(s.size() - i - 2) + s[s.size() - 1];
    }

    void insertWord(Node *root, const string &s) {
        for (const auto &ch: s) {
            auto i = ch - 'a';
            if (!root->children[i]) {
                root->children[i] = new Node();
            }
            root = root->children[i];
            ++root->cnt;
        }
    }

    int findLeaf(Node *root, const string &s) {
        for (int i = 0; i < (int) s.size(); ++i) {
            auto j = s[i] - 'a';
            if (!root->children[j]) {
                return -1;
            }
            root = root->children[j];
            if (root->cnt == 1) {
                return i;
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0527_H
