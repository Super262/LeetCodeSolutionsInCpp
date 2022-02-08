//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0609_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0609_H

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(const vector<string> &paths) {
        stringstream ssin;
        string dir, file;
        unordered_map<string, vector<string>> group;
        for (const auto &p: paths) {
            ssin.str(p);
            ssin >> dir;
            while (ssin >> file) {
                auto st = file.find_first_of('(');
                auto content = file.substr(st + 1, (file.size() - 2) - (st + 1) + 1);
                group[content].emplace_back(dir + '/' + file.substr(0, st));
            }
            ssin.clear();
        }
        vector<vector<string>> ans;
        for (auto &item: group) {
            if (item.second.size() > 1) {
                ans.emplace_back(item.second);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0609_H
