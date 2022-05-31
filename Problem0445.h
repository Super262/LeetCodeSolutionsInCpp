//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0445_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0445_H

#include "listnode.h"

class Solution {
    // 不翻转l1、l2，直接计算：统计l1、l2的长度为n1、n2；顺序遍历l1、l2，从高位开始求和，不进位，将新节点以"头插法"插入结果链表中
    // 此时，结果链表是最终结果的倒序，且尚未进位；我从头遍历当前结果以进位；最后，翻转当前结果，得到最终答案
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto p1 = l1;
        auto p2 = l2;
        int n1 = 0;  // l1的长度
        int n2 = 0;  // l2的长度
        while (p1) {
            ++n1;
            p1 = p1->next;
        }
        while (p2) {
            ++n2;
            p2 = p2->next;
        }
        p1 = l1;
        p2 = l2;
        ListNode *head = nullptr;
        while (n1 || n2) {  // 从高位开始求对应位的和
            int t = 0;
            if (n1 > n2) {
                t += p1->val;
                p1 = p1->next;
                --n1;
            } else if (n2 > n1) {
                t += p2->val;
                p2 = p2->next;
                --n2;
            } else {
                t += p1->val + p2->val;
                p1 = p1->next;
                p2 = p2->next;
                --n2;
                --n1;
            }
            auto node = new ListNode(t);
            node->next = head;
            head = node;
        }
        ListNode *a = nullptr;
        auto b = head;
        int carry = 0;
        while (b) {  // 进位
            carry += b->val;
            b->val = carry % 10;
            carry /= 10;
            a = b;
            b = b->next;
        }
        while (carry) {  // 处理剩余进位
            a->next = new ListNode(carry % 10);
            carry /= 10;
            a = a->next;
        }
        a = nullptr;
        b = head;
        while (b) {  // 翻转
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0445_H
