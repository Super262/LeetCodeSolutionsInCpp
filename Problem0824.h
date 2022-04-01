//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0824_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0824_H

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string toGoatLatin(const string &s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        string ans;
        for (int i = 0, k = 1; i < s.size(); ++i) {
            auto j = i;
            while (j < s.size() && s[j] != ' ') {
                ++j;
            }
            auto word = s.substr(i, j - i);
            if (word.size() > 1 && !vowels.count((char) tolower(word[0]))) {
                word = word.substr(1) + word[0];
            }
            word += "ma";
            word += string(k, 'a');
            ans += word;
            ans += ' ';
            i = j;
            ++k;
        }
        ans.pop_back();
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0824_H
