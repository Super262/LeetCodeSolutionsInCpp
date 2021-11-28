//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0430_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0430_H

#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        auto res = dfs(head);
        return res.first;
    }

private:
    pair<Node *, Node *> dfs(Node *head) {  // 由于是双链表，所以头节点和尾节点都要被返回
        if (!head) {
            return {nullptr, nullptr};
        }
        auto current = head;
        auto tail = head;
        while (current) {
            tail = current;
            if (current->child) {
                auto t = dfs(current->child);  // 递归解析
                current->child = nullptr;  // 别忘记清除child指针
                t.second->next = current->next;  // 接合链表
                if (current->next) {
                    current->next->prev = t.second;
                }
                current->next = t.first;
                t.first->prev = current;
                current = t.second;
                tail = current;
            }
            current = current->next;
        }
        return {head, tail};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0430_H
