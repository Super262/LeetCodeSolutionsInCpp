//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0432_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0432_H

#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class AllOne {
    // 双链表保存key的频率：1 -> 2 -> 3 -> ...
public:
    AllOne() {
        head = new Node(INT_MIN);
        tail = new Node(INT_MAX);
        head->next = tail;
        tail->prev = head;
    }

    void inc(const string &key) {
        if (storage.count(key) == 0) {
            storage[key] = addToNext(head, key, 1);
        } else {
            auto node = storage[key];
            node->pool.erase(key);
            storage[key] = addToNext(node, key, node->value + 1);
            if (node->pool.empty()) {
                deleteNode(node);
            }
        }
    }

    void dec(const string &key) {
        if (!storage.count(key)) {
            return;
        }
        auto node = storage[key];
        node->pool.erase(key);
        if (node->value > 1) {
            storage[key] = addToPrev(node, key, node->value - 1);
        } else {
            storage.erase(key);
        }
        if (node->pool.empty()) {
            deleteNode(node);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) {
            return "";
        }
        return *(tail->prev->pool.begin());
    }

    string getMinKey() {
        if (head->next == tail) {
            return "";
        }
        return *(head->next->pool.begin());
    }

private:
    struct Node {
        Node *prev;
        Node *next;
        int value;
        unordered_set<string> pool;

        Node(int v) {
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node *head;
    Node *tail;
    unordered_map<string, Node *> storage;

    Node *addToNext(Node *node, const string &key, int val) {
        if (node->next->value == val) {
            node->next->pool.insert(key);
        } else {
            auto t = new Node(val);
            t->pool.insert(key);
            t->next = node->next;
            node->next->prev = t;
            node->next = t;
            t->prev = node;
        }
        return node->next;
    }

    Node *addToPrev(Node *node, const string &key, int val) {
        if (node->prev->value == val) {
            node->prev->pool.insert(key);
        } else {
            auto t = new Node(val);
            t->pool.insert(key);
            t->prev = node->prev;
            node->prev->next = t;
            t->next = node;
            node->prev = t;
        }
        return node->prev;
    }

    void deleteNode(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = nullptr;
        node->next = nullptr;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0432_H
