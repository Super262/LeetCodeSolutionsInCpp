//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0460_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0460_H

#include <unordered_map>

using namespace std;

class LFUCache {
    // 2层双链表，2个哈希表，所有操作时间复杂度均为O(1)
    // 外层链表串联Block，每个Block存储频率为freq的关键字，从头到尾每个Block对应的频率递增
    // 每个Block内包含1个双链表，每个双链表的Node存储频率为freq的关键字，按上次被访问的时间、从头到尾、由近到远排序
    // 2个哈希表分别保存关键字对应的Block、关键字对应的Node
    // 查询关键字key时，更新key到下个Block的头部；存储(key,value)时，若key已存在，则更新key到下个Block的头部
    // 若key不存在，且此时Node个数达到上限，删除最后的Block的最后的Node，再将(key,value)存入freq为1的Block中
public:
    LFUCache(int capacity) {
        cap = capacity;  // 注意，容量cap的合法值包含0，注意特殊处理
        head = new Block(0);
        tail = new Block(INT_MAX);
        head->right = tail;
        tail->left = head;
    }

    int get(int key) {
        if (cap == 0 || !key_to_node.count(key)) {
            return -1;
        }
        auto block = key_to_block[key];
        auto node = key_to_node[key];

        // 当前node被访问，需移动node到代表更高频率的Block的头部
        block->detach(node);
        if (block->right->freq != block->freq + 1) {
            createNext(block);
        }
        block->right->addFirst(node);
        key_to_block[key] = block->right;
        if (block->empty()) {
            erase(block);
        }

        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        if (key_to_block.count(key)) {
            key_to_node[key]->val = value;
            get(key);  // 复用get函数，移动node到代表更高频率的Block的头部
            return;
        }
        if (key_to_node.size() == cap) {
            auto p = head->right->tail->left;  // 删除freq最小的Block的最后的节点
            head->right->detach(p);
            if (head->right->empty()) {
                erase(head->right);
            }
            key_to_node.erase(p->key);
            key_to_block.erase(p->key);
            delete p;
        }
        auto p = new Node(key, value);
        if (head->right->freq > 1) {  // 当前不存在freq为1的Block
            createNext(head);
        }
        head->right->addFirst(p);
        key_to_node[key] = p;
        key_to_block[key] = head->right;
    }

private:
    struct Node {
        Node *left;
        Node *right;
        int key;
        int val;

        Node(int k, int v) {
            key = k;
            val = v;
            left = nullptr;
            right = nullptr;
        }
    };

    struct Block {
        Block *left;
        Block *right;
        Node *head;
        Node *tail;
        int freq;

        Block(int f) {
            freq = f;
            left = nullptr;
            right = nullptr;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->right = tail;
            tail->left = head;
        }

        void addFirst(Node *node) {
            node->right = head->right;
            head->right = node;
            node->right->left = node;
            node->left = head;
        }

        void detach(Node *node) {
            node->left->right = node->right;
            node->right->left = node->left;
        }

        bool empty() {
            return head->right == tail;
        }

        ~Block() {
            while (head) {
                auto t = head->right;
                delete head;
                head = t;
            }
        }
    };

    int cap;
    Block *head;
    Block *tail;
    unordered_map<int, Block *> key_to_block;
    unordered_map<int, Node *> key_to_node;

    void createNext(Block *b) {  // 在b的右侧插入新块p：p->freq=b->freq+1
        auto p = new Block(b->freq + 1);
        p->right = b->right;
        b->right->left = p;
        p->left = b;
        b->right = p;
    }

    void erase(Block *b) {
        b->left->right = b->right;
        b->right->left = b->left;
        delete b;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0460_H
