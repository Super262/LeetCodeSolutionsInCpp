//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0138_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0138_H

#include "node_random.h"

class Problem0138 {
    // 巧妙方法（空间O(1)），直接背诵：将复制a后生成的新节点a'暂存为a的后继（a->next=a'），最后分离新链和旧链
public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return head;
        }
        for (auto cur = head; cur; cur = cur->next->next) {  // 将新节点保存为老节点的后继
            auto t = new Node(cur->val);
            t->next = cur->next;
            cur->next = t;
        }
        for (auto cur = head; cur; cur = cur->next->next) {  // 构建新链表的random指针
            if (!cur->random) {
                continue;
            }
            cur->next->random = cur->random->next;
        }
        auto dummy = new Node(-1);
        auto cur = dummy;
        for (auto p = head; p; p = p->next) {  // 分离新链表
            cur->next = p->next;
            cur = cur->next;
            p->next = cur->next;  // 重要步骤：拆链
            cur->next = nullptr;
        }
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0138_H
