//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0721_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0721_H

#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
    // 并查集 + set去重（题目要求有序输出结果）
public:
    vector<vector<string>> accountsMerge(const vector<vector<string>> &accounts) {
        const auto n = (int) accounts.size();
        int parent[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        unordered_map<string, vector<int>> email_to_id;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                email_to_id[accounts[i][j]].emplace_back(i);
            }
        }
        for (const auto &item: email_to_id) {  // 合并相关集合
            const auto &ids = item.second;
            for (int i = 1; i < ids.size(); ++i) {
                parent[findRoot(parent, ids[i])] = findRoot(parent, ids[0]);
            }
        }
        vector<set<string>> parent_emails(n);  // 集合i对应的邮件地址
        for (int i = 0; i < n; ++i) {
            auto pid = findRoot(parent, i);
            for (int j = 1; j < accounts[i].size(); ++j) {
                parent_emails[pid].emplace(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for (int i = 0; i < n; ++i) {
            if (parent_emails[i].empty()) {
                continue;
            }
            vector<string> t;
            t.emplace_back(accounts[i][0]);
            for (const auto &s: parent_emails[i]) {
                t.emplace_back(s);
            }
            res.emplace_back(t);
        }
        return res;
    }

private:
    int findRoot(int parent[], int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent, parent[x]);
        }
        return parent[x];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0721_H
