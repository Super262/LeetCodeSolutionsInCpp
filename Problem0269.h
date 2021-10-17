//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0269_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0269_H

#include <cstring>
#include <string>

using namespace std;

class Problem0269 {
public:
    void addEdge(int headIdx[], int nextIdx[], int vertexValue[], const int a, const int b, int &idx) {
        vertexValue[idx] = b;
        nextIdx[idx] = headIdx[a];
        headIdx[a] = idx;
        ++idx;
    }

    string topoSort(const int headIdx[],
                    const int nextIdx[],
                    const int vertexValue[],
                    const bool nodeExisted[],
                    int inDegree[]) {
        int q[28];
        int hh = 0, tt = -1;
        for (int i = 1; i <= 26; ++i) {
            if (nodeExisted[i] && inDegree[i] == 0) {
                q[++tt] = i;
            }
        }
        string result;
        while (hh <= tt) {
            auto root = q[hh++];
            result.push_back((char) ('a' + root - 1));
            for (int idx = headIdx[root]; idx != -1; idx = nextIdx[idx]) {
                auto childV = vertexValue[idx];
                --inDegree[childV];
                if (inDegree[childV] == 0) {
                    q[++tt] = childV;
                }
            }
        }
        return result;
    }

    string alienOrder(vector<string> &words) {
        int headIdx[27];
        int nextIdx[words.size() * 2 + 1];
        int vertexValue[words.size() * 2 + 1];
        memset(headIdx, -1, sizeof headIdx);  // -1为索引的无效值
        memset(nextIdx, -1, sizeof nextIdx);
        memset(vertexValue, 0, sizeof vertexValue);  // 0为顶点编号的无效值

        // Generate nodes
        int nodesCount = 0;
        bool nodeExisted[27];
        memset(nodeExisted, 0, sizeof nodeExisted);
        for (const auto &s: words) {
            for (auto ch: s) {
                if (nodeExisted[ch - 'a' + 1]) {
                    continue;
                }
                nodeExisted[ch - 'a' + 1] = true;
                ++nodesCount;
            }
        }

        // Build the map.
        int idx = 0;
        int inDegree[27];
        memset(inDegree, 0, sizeof inDegree);
        for (int i = 1; i < words.size(); ++i) {
            const auto &s1 = words[i - 1];
            const auto &s2 = words[i];
            if (s1.size() > s2.size() && s1.find(s2) == 0) {   // words的顺序无效：s1比s2长，且s1完全包含s2
                return "";
            }
            int j;
            for (j = 0; j < (int) min(s1.size(), s2.size()); ++j) {
                if (s1[j] == s2[j]) {
                    continue;
                }
                break;
            }
            if (j == (int) min(s1.size(), s2.size())) {  // s1和s2没有不相同的元素，跳过
                continue;
            }
            addEdge(headIdx, nextIdx, vertexValue, s1[j] - 'a' + 1, s2[j] - 'a' + 1, idx);
            ++inDegree[s2[j] - 'a' + 1];
        }

        // Topological Order
        string result = topoSort(headIdx, nextIdx, vertexValue, nodeExisted, inDegree);
        if (result.size() < nodesCount) {
            return "";
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0269_H
