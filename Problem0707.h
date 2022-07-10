//
// Created by Fengwei Zhang on 2/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0707_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0707_H

class MyLinkedList {
    // 设置全局变量head和tail，分别指示链表头部、尾部
    // 查询：输入为index，从头部开始遍历，直到移动index步到达p，返回p->val
    // 插入：输入为index，从头部开始遍历，直到移动index-1步到达p，在p后插入新节点；特殊情况：链表为空、头部插入、尾部插入
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {  // 索引无效
            return -1;
        }
        auto p = head;
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val) {
        if (!head) {
            head = new Node(val);
            tail = head;
        } else {
            auto node = new Node(val);
            node->next = head;
            head = node;
        }
        ++size;
    }

    void addAtTail(int val) {
        if (!head) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
        ++size;
    }

    void addAtIndex(int index, int val) {
        if (index > size) { // 索引无效
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        auto p = head;
        for (int i = 0; i < index - 1; ++i) {  // 找到index的前驱
            p = p->next;
        }
        auto t = new Node(val);
        t->next = p->next;
        p->next = t;
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {  // 索引无效
            return;
        }
        if (index == 0) {  // 特殊情况：删除头结点
            auto t = head->next;
            delete head;
            head = t;
            --size;
            return;
        }
        auto p = head;
        for (int i = 0; i < index - 1; ++i) {  // 找到index的前驱
            p = p->next;
        }
        if (p->next == tail) {  // 特殊情况：删除尾结点
            delete tail;
            tail = p;
            --size;
            return;
        }
        auto t = p->next->next;
        delete p->next;
        p->next = t;
        --size;
    }

private:
    struct Node {
        int val;
        Node *next;

        Node(int v) {
            val = v;
            next = nullptr;
        }
    };

    Node *head, *tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0707_H
