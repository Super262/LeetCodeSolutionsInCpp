//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0399_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0399_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    // 这里是并查集做法，最短路做法（Floyd）见注释
    // 我们将变量视作节点，边表示变量间的倍数关系；parent[x]表示变量x此时的就近父节点（注意：不一定就是根结点，若尚未进行路径压缩）
    // 设px=parent[x]，factor[x]是"x/px"的值；在递归搜寻x的根结点时，我们会进行路径压缩，并更新factor[x]为"x/root"的值
    // 建立除法关系"a/b=v"时，我们合并2个集合，更新相关倍数："factor[pa] = factor[b] * v / factor[a]; parent[pa] = pb;"
public:
    vector<double> calcEquation(const vector<vector<string>> &equations,
                                const vector<double> &values,
                                const vector<vector<string>> &queries) {
        unordered_map<string, string> parent;
        unordered_map<string, double> factor;
        const auto n = (int) equations.size();
        for (int i = 0; i < n; ++i) {
            const auto &a = equations[i][0];
            const auto &b = equations[i][1];
            mergeSets(a, b, values[i], parent, factor);  // 建立除法关系
        }
        vector<double> ans;
        ans.reserve(queries.size());
        for (const auto &q: queries) {
            const auto &a = q[0];
            const auto &b = q[1];
            if (!parent.count(a) || !parent.count(b)) {  // 不存在的点
                ans.emplace_back(-1);
                continue;
            }
            auto pa = findRoot(a, parent, factor);
            auto pb = findRoot(b, parent, factor);
            if (pa != pb) {  // 不在同个集合，无法确定倍数
                ans.emplace_back(-1);
            } else {
                ans.emplace_back(factor[a] / factor[b]);
            }
        }
        return ans;
    }

private:
    string findRoot(const string &x,
                    unordered_map<string, string> &parent,
                    unordered_map<string, double> &factor) {
        if (!parent.count(x)) {
            parent[x] = x;
            factor[x] = 1;
        }
        if (parent[x] != x) {
            auto t = parent[x];
            parent[x] = findRoot(parent[x], parent, factor);
            factor[x] *= factor[t];
        }
        return parent[x];
    }

    void mergeSets(const string &a,
                   const string &b,
                   double value,
                   unordered_map<string, string> &parent,
                   unordered_map<string, double> &factor) {
        auto pa = findRoot(a, parent, factor);
        auto pb = findRoot(b, parent, factor);
        if (pa == pb) {
            return;
        }
        factor[pa] = factor[b] * value / factor[a];
        parent[pa] = pb;
    }
};

//class Solution {
//    // 1. 转化为图论问题：变量为点，比值（除法操作）为正向边，比值的倒数为反向边
//    // 2. Floyd 预处理最短距离，根据每个查询返回答案
//public:
//    vector<double> calcEquation(const vector<vector<string>> &equations,
//                                const vector<double> &values,
//                                const vector<vector<string>> &queries) {
//        unordered_set<string> vertices;
//        unordered_map<string, unordered_map<string, double>> dist;
//        const auto n = (int) equations.size();
//        vertices.reserve(n * 2);
//        dist.reserve(n * 2);
//        for (int i = 0; i < n; ++i) {
//            auto &edge = equations[i];
//            auto &d = values[i];
//            vertices.insert(edge[0]);
//            vertices.insert(edge[1]);
//            dist[edge[0]][edge[1]] = d;
//            dist[edge[1]][edge[0]] = 1 / d;
//        }
//        for (const auto &mid: vertices) {
//            for (const auto &st: vertices) {
//                for (const auto &ed: vertices) {
//                    if (!dist[st].count(mid) || !dist[mid].count(ed)) {
//                        continue;
//                    }
//                    dist[st][ed] = dist[st][mid] * dist[mid][ed];
//                }
//            }
//        }
//        vector<double> res;
//        res.reserve(queries.size());
//        for (const auto &q: queries) {
//            if (!vertices.count(q[0]) || !vertices.count(q[1]) || !dist[q[0]].count(q[1])) {
//                res.emplace_back(-1);
//                continue;
//            }
//            res.emplace_back(dist[q[0]][q[1]]);
//        }
//        return res;
//    }
//};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0399_H
