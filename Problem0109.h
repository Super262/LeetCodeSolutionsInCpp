//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0109_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0109_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0109 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return NULL;
        }
        int n = 0;
        auto current = head;
        while (current) {
            ++n;
            current = current->next;
        }
        if (n == 1) {
            return new TreeNode(head->val);
        }
        current = head;
        for (int i = 0; i < n / 2 - 1; ++i) {
            current = current->next;
        }
        auto root = new TreeNode(current->next->val);
        root->right = sortedListToBST(current->next->next);
        current->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0109_H
