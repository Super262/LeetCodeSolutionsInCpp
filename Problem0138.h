//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0138_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0138_H

#include "node.h"

class Solution {
    // 巧妙方法（空间O(1)），直接背诵：将复制a后生成的新节点a'暂存为a的后继（a->next=a'），最后分离新链和旧链
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
            p->next = q->next;  // 重要步骤：拆链
        }
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0138_H
