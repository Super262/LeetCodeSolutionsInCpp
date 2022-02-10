//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0648_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0648_H

#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
    // 经典算法，必须掌握：字符串哈希或Trie
public:
    string replaceWords(const vector<string> &dict, const string &s) {
        const int P = 131;
        unordered_set<unsigned long long> hash;
        for (const auto &w: dict) {
            unsigned long long h = 0;
            for (const auto &ch: w) {
                h = h * P + ch;
            }
            hash.insert(h);
        }
        stringstream ssin(s);
        string res, temp;
        while (ssin >> temp) {
            unsigned long long h = 0;
            int i;
            for (i = 0; i < (int) temp.size(); ++i) {
                h = h * P + temp[i];
                if (hash.count(h)) {
                    break;
                }
            }
            res += temp.substr(0, i + 1);
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0648_H
