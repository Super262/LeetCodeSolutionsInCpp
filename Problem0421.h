//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0421_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0421_H

#include <vector>

using namespace std;

class Solution {
    // Trie求解最大异或对，类似AcWing 143
public:
    int findMaximumXOR(const vector<int> &nums) {
        auto root = new Node();
        int res = 0;
        for (const int &x: nums) {
            insert(root, x);
            res = max(res, searchMaxXOR(root, x));
        }
        return res;
    }

private:
    struct Node {
        bool is_num;
        Node *next[2]{};

        Node() {
            is_num = false;
            next[0] = nullptr;
            next[1] = nullptr;
        }
    };

    void insert(Node *root, const int &x) {
        auto p = root;
        for (int i = 30; i >= 0; --i) {  // x最大为2^31，最多可向左移30位
            if (((x >> i) & 1) == 1) {
                if (!p->next[1]) {  // 字典树：只有当后继节点不存在时，才创建新的后继节点
                    p->next[1] = new Node();
                }
                p = p->next[1];
            } else {
                if (!p->next[0]) {
                    p->next[0] = new Node();
                }
                p = p->next[0];
            }
        }
        p->is_num = true;
    }

    int searchMaxXOR(Node *root, const int &x) {
        int res = 0;
        auto p = root;
        for (int i = 30; i >= 0; --i) {  // x最大为2^31，最多可向左移30位
            res *= 2;
            if (((x >> i) & 1) == 1) {
                if (p->next[0]) {
                    p = p->next[0];
                    res += 1;
                } else {
                    p = p->next[1];
                }
            } else {
                if (p->next[1]) {
                    p = p->next[1];
                    res += 1;
                } else {
                    p = p->next[0];
                }
            }
        }
        return res;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0421_H
