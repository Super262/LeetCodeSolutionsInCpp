//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0720_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0720_H

#include <vector>
#include <string>

using namespace std;

class Problem0720 {
    // Trie+前序遍历；首先，我们将所有单词插入Trie，Trie中节点保存前缀（从根出发的路径）对应的单词
    // 若答案是w，则w的所有前缀均有效；为保证答案w的字典序最小，我们采取先序遍历，先保存字典序较小的单词为答案
public:
    string longestWord(const vector<string> &words) {
        auto root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            insert(root, words[i], i);
        }
        auto ans = preOrder(root, 0);
        if (ans.second == -1) {
            return "";
        }
        return words[ans.second];
    }

private:
    struct Node {
        int idx;
        Node *items[26]{};

        Node() {
            idx = -1;
            for (auto &x: items) {
                x = nullptr;
            }
        }
    };

    void insert(Node *root, const string &w, const int idx) {
        for (const auto &ch: w) {
            auto i = ch - 'a';
            if (!root->items[i]) {
                root->items[i] = new Node();
            }
            root = root->items[i];
        }
        root->idx = idx;
    }

    pair<int, int> preOrder(Node *root, int l) {  // 返回(l,i)，l是当前最长的前缀长度，words[i]是这个最长前缀对应的单词
        pair<int, int> res(l, root->idx);
        for (const auto kid: root->items) {
            if (!kid || kid->idx == -1) {  // 不要忘记排除idx=-1的结点（idx=-1说明前缀无效）
                continue;
            }
            auto t = preOrder(kid, l + 1);
            if (t.first > res.first) {
                res.first = t.first;
                res.second = t.second;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0720_H
