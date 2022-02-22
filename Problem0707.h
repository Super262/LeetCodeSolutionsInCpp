//
// Created by Fengwei Zhang on 2/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0707_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0707_H

class MyLinkedList {
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
