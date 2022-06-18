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
    // 根据题意，我们总结出以下贪心思想：对于任意单词w，我们力求将w缩写到最短，并且w的缩写与其它单词的缩写不同
    // 若w的最短缩写w[0]+"K"+w[n-1]是唯一的，我们保留此缩写；若发生重复，我们选择尽可能少地暴露w的前缀，生成新缩写
    // 涉及到字符串的前缀重合问题，我们可以使用Trie解决：设集合S，S中所有单词的最短缩写相同，将S中所有单词加入一个Trie
    // Trie的每个节点记录它被遍历的频率；对于S中每个单词w，我们查找最小的i，满足w[i]所在节点的频率为1，w的缩写是w[0:i]+"n-i-2"+w[n-1]
public:
    vector<string> wordsAbbreviation(const vector<string> &words) {
        unordered_map<string, vector<int>> abbr_words;  // abbr_words[s]：最短缩写为s的所有单词
        for (int i = 0; i < (int) words.size(); ++i) {
            abbr_words[abbreviate(words[i], 0)].emplace_back(i);
        }
        vector<string> ans(words.size());
        for (const auto &item: abbr_words) {
            auto root = new Node();  // 为每组单词新建Trie
            for (const auto &i: item.second) {
                insertWord(root, words[i]);
            }
            for (const auto &i: item.second) {
                auto j = findLeaf(root, words[i]);  // 查找"叶路径"的起点
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
