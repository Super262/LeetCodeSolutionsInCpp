//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0092_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0092_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Problem0092 {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left >= right) {  // 边界值：待反转区域长度小于2
            return head;
        }

        ListNode *dummyNode = new ListNode(-501);
        dummyNode->next = head;

        ListNode *leftStartPrev = dummyNode;  // 待反转区域的前驱节点
        ListNode *leftStart = head;  // 待反转区域的头节点

        // 用于链表反转的3个指针（前、中、后）
        ListNode *prev = head;
        ListNode *current = prev->next;
        ListNode *temp = current->next;

        for (int i = 1; i < left; ++i) {
            leftStartPrev = leftStartPrev->next;
            leftStart = leftStart->next;
            prev = prev->next;
            current = current->next;
            temp = temp->next;
        }

        ListNode *rightEnd;  // 待反转区域的末尾节点
        ListNode *rightEndNext; // 待反转区域的后继节点

        for (int i = left; i < right; ++i) { // 反转并更新后继和末尾节点
            rightEnd = current;
            current->next = prev;
            prev = current;
            current = temp;
            rightEndNext = current;
            if (temp) {
                temp = temp->next;
            }
        }

        leftStartPrev->next = rightEnd;
        leftStart->next = rightEndNext;

        return dummyNode->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0092_H
