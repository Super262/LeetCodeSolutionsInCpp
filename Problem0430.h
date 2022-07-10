//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0430_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0430_H

#include <vector>
#include "node_double.h"

using namespace std;

class Solution {
    // 递归解析，返回解析后得到的头节点和尾节点
public:
    Node *flatten(Node *head) {
        if (!head) {
            return nullptr;
        }
        auto res = dfs(head);
        return res.first;
    }

private:
    pair<Node *, Node *> dfs(Node *head) {  // 由于是双链表，所以头节点和尾节点都要被返回
        auto current = head;
        auto tail = head;
        while (current) {
            tail = current;
            if (!current->child) {
                current = current->next;
                continue;
            }
            auto t = dfs(current->child);
            current->child = nullptr;  // 别忘记清除child指针
            t.second->next = current->next;  // 接合链表
            if (current->next) {
                current->next->prev = t.second;
            }
            current->next = t.first;
            t.first->prev = current;
            tail = t.second;
            current = tail->next;
        }
        return {head, tail};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0430_H
