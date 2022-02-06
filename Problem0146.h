//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0146_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0146_H

#include <unordered_map>

using namespace std;

class LRUCache {
    // https://www.acwing.com/solution/content/1013/
    // 双链表的价值：O(1)删除
public:
    LRUCache(const int c) {
        size = 0;
        capacity = c;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(const int key) {
        if (!index.count(key)) {
            return -1;
        }
        auto node = index[key];
        detach(node);
        addLast(node);
        return node->value;
    }

    void put(const int key, const int value) {
        if (index.count(key)) {
            auto node = index[key];
            detach(node);
            node->value = value;
            addLast(node);
            return;
        }
        if (size == capacity) {
            auto node = head->next;
            index.erase(node->key);
            detach(node);
            delete node;
            --size;
        }
        ++size;
        auto node = new Node(key, value);
        addLast(node);
        index[key] = node;
    }

private:
    struct Node {
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(const int k, const int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    int size;
    Node *head;  // 节点越靠近head，被使用的频率越低
    Node *tail;
    unordered_map<int, Node *> index;

    void detach(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void addLast(Node *node) {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0146_H
