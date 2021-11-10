//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0138_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0138_H

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Problem0138 {
public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return head;
        }
        // O(1)空间做法：将新节点保存为老节点的后继
        for (auto p = head; p; p = p->next->next) {
            auto q = new Node(p->val);
            q->next = p->next;
            p->next = q;
        }
        // 构建新链表的random指针
        for (auto p = head; p; p = p->next->next) {
            if (!p->random) {
                continue;
            }
            p->next->random = p->random->next;
        }
        // 分离新链表
        auto dummy = new Node(-1);
        auto current = dummy;
        for (auto p = head; p; p = p->next) {
            auto q = p->next;
            current->next = q;
            current = current->next;
            p->next = q->next;
        }
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0138_H
