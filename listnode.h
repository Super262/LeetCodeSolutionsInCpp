//
// Created by Fengwei Zhang on 5/2/22.
//

#ifndef LEETCODESOLUTIONSINCPP_LISTNODE_H
#define LEETCODESOLUTIONSINCPP_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //LEETCODESOLUTIONSINCPP_LISTNODE_H
