//
// Created by Fengwei Zhang on 7/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0716_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0716_H

#include <map>
#include <vector>

using namespace std;

class MaxStack {
    // 双向链表+Map，实现高效popMax操作；双向链表删除操作时间复杂度为O(1)，Map查询操作时间复杂度为O(logN)
    // Map保存"(元素，节点数组)"映射；删除时，弹出数组尾部、从双链表移除对应节点；std::prev(map.end())返回Map最大的key
public:
    MaxStack() = default;

    void push(int x) {
        auto node = dll.emplace(x);
        data[x].emplace_back(node);
    }

    int pop() {
        auto x = dll.top();
        dll.pop();
        auto &arr = data[x];
        arr.pop_back();
        if (arr.empty()) {
            data.erase(x);
        }
        return x;
    }

    int top() {
        return dll.top();
    }

    int peekMax() {
        return prev(data.end())->first;
    }

    int popMax() {
        auto x = peekMax();
        auto &arr = data[x];
        dll.erase(arr.back());
        arr.pop_back();
        if (arr.empty()) {
            data.erase(x);
        }
        return x;
    }

private:
    struct Node {
        int val;
        Node *prev;
        Node *next;

        Node(int val) {
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    class DoubleLinkedList {
    private:
        Node *head;
        Node *tail;
    public:
        DoubleLinkedList() {
            head = new Node(0);
            tail = new Node(0);
            head->next = tail;
            tail->prev = head;
        }

        int top() {
            return tail->prev->val;
        }

        Node *emplace(int x) {
            auto t = new Node(x);
            auto p = tail->prev;
            p->next = t;
            t->prev = p;
            t->next = tail;
            tail->prev = t;
            return t;
        }

        void pop() {
            erase(tail->prev);
        }

        void erase(Node *node) {
            auto p = node->prev;
            p->next = node->next;
            node->next->prev = p;
            delete node;
        }
    };

    DoubleLinkedList dll;
    map<int, vector<Node *>> data;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0716_H
