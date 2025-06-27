#pragma once

#include <stdafx.h>

namespace Model_Iterator
{
    class Iterator;
    // 定义一个节点
    struct Node
    {
        std::string _name{};
        Node *next = nullptr;
        Node *prev = nullptr;

        Node(std::string n) : _name(n) {}
    };

    // 定义双向链表
    class MyList
    {
    public:
        inline int getCount() const { return m_count; }
        inline Node *head() const { return m_head; }
        inline Node *tail() const { return m_tail; }
        Node *insert(Node *node, std::string name);
        Node *pushFront(std::string name);
        Node *pushBack(std::string name);
        Iterator *getIterator(bool isReverse = true);

    private:
        Node *m_head = nullptr;
        Node *m_tail = nullptr;
        int m_count = 0;
    };
} // namespace Model_Iterator
