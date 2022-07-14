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

class Problem0721 {
    // 并查集 + set去重（题目要求有序输出结果）
public:
    vector<vector<string>> accountsMerge(const vector<vector<string>> &accounts) {
        const auto n = (int) accounts.size();
        int parent[n];
        int set_size[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        unordered_map<string, vector<int>> email_to_id;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < (int) accounts[i].size(); ++j) {
                email_to_id[accounts[i][j]].emplace_back(i);
            }
        }
        for (const auto &item: email_to_id) {  // 合并相关集合
            const auto &ids = item.second;
            for (const auto &id: item.second) {
                mergeSets(findRoot(parent, item.second[0]), findRoot(parent, id), parent, set_size);
            }
        }
        vector<set<string>> parent_emails(n);  // 集合i对应的邮件地址
        for (int i = 0; i < n; ++i) {
            auto pid = findRoot(parent, i);
            for (int j = 1; j < accounts[i].size(); ++j) {
                parent_emails[pid].emplace(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i) {
            if (parent_emails[i].empty()) {
                continue;
            }
            vector<string> t;
            t.emplace_back(accounts[i][0]);
            for (const auto &s: parent_emails[i]) {
                t.emplace_back(s);
            }
            ans.emplace_back(t);
        }
        return ans;
    }

private:
    int findRoot(int parent[], int x) {
        auto u = parent[x];
        while (u != parent[u]) {
            u = parent[u];
        }
        while (x != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    int mergeSets(int a, int b, int parent[], int set_size[]) {
        if (a == b) {
            return -1;
        }
        if (set_size[a] > set_size[b]) {
            set_size[a] += set_size[b];
            parent[b] = a;
            return a;
        }
        set_size[b] += set_size[a];
        parent[a] = b;
        return b;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0721_H
