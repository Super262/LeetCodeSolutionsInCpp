//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0804_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0804_H

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(const vector<string> &words) {
        string ch_to_m[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                              "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                              "-.--", "--.."};
        unordered_set<string> morses;
        for (const auto &w: words) {
            string m;
            for (const char &ch: w) {
                m += ch_to_m[ch - 'a'];
            }
            morses.insert(m);
        }
        return (int) morses.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0804_H
