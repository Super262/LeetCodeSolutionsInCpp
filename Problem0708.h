
//
// Created by Fengwei Zhang on 7/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0708_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0708_H

#include "node_list.h"

class Solution {
    // 若head，直接初始化head为新节点，设置head->next=head
    // head不空，从head开始遍历，设当前节点为p；若p->val<=x<=p->next->val，直接将x插入到p后面
    // 若发现p->val<p->next->val，说明p是最大值节点，p->next是最小值节点；若x大于最大值，或者x小于最小值，直接将x插入到p后面
    // 若完全遍历后，仍未找到插入位置，说明链表内所有节点值相同，直接将x插入到head后面
public:
    Node *insert(Node *head, int value) {
        if (!head) {
            head = new Node(value);
            head->next = head;
            return head;
        }
        auto p = head;
        do {
            if (p->val <= value && value <= p->next->val) {
                insertAsNext(p, value);
                return head;
            }
            if (p->val > p->next->val) {
                if (value > p->val || value < p->next->val) {
                    insertAsNext(p, value);
                    return head;
                }
            }
            p = p->next;
        } while (p != head);
        insertAsNext(head, value);
        return head;
    }

private:
    static void insertAsNext(Node *p, int val) {
        auto q = p->next;
        p->next = new Node(val);
        p->next->next = q;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0708_H
