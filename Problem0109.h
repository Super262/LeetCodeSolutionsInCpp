//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0109_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0109_H

#include "listnode.h"
#include "treenode.h"

class Problem0109 {
    // 经典算法，必须掌握：遍历链表，找到中间节点m，然后分别递归处理[0:m-1]、[m+1:n]
    // 类似中序遍历，先右后左，不要忘记"拆链"操作
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        int n = 0;
        auto current = head;
        while (current) {  // 获得链表长度n
            ++n;
            current = current->next;
        }
        if (n == 1) {
            return new TreeNode(head->val);
        }
        current = head;
        for (int i = 0; i < n / 2 - 1; ++i) {  // 找到中点的前驱结点
            current = current->next;
        }
        auto root = new TreeNode(current->next->val);
        root->right = sortedListToBST(current->next->next);
        current->next = nullptr;  // 不要忘记"拆链"操作
        root->left = sortedListToBST(head);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0109_H
