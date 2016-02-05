#pragma once

#include <string>

const int TABLE_SIZE = 50;

template <typename T> struct Node {
    std::string key;
    T data;
    Node *next;
};

template <typename T> class myHashTable {
private:
    Node<T> _table[TABLE_SIZE];

    int h(const std::string &key) {
        int temp = 0;
        for (int i = 0; i != key.size() && i != 3; ++i) {
            temp += key[i];
        }
        return (temp%TABLE_SIZE);
    }

    void release(Node<T> *node) {
        if (node) {
            release(node->next);
            delete node;
        }
    }

public:
    myHashTable() {
        for (int i = 0; i != TABLE_SIZE; ++i) {
            _table[i].next = NULL;
        }
    }

    ~myHashTable() {
        for (int i = 0; i != TABLE_SIZE; ++i) {
            Node<T> *node = _table[i].next;
            release(node);
        }
    }
    
    bool add(const std::string &key, T data) {
        int id = h(key);
        Node<T> *node = &_table[id];
        while (node->next) {
            node = node->next;
        }

        Node<T> *newnode = new Node<T>();
        newnode->key = key;
        newnode->data = data;
        newnode->next = NULL;
        
        node->next = newnode;
        return true;
    }

    bool remove(const std::string &key) {
        int id = h(key);
        Node<T> *node = &_table[id];
        while (node->next && node->next->key != key) {
            node = node->next;
        }

        if (node->next) {
            Node<T> *temp = node->next;
            node->next = node->next->next;
            delete temp;
            return true;
        } else {
            return false;
        }
    }
    
    T find(const std::string &key, T flag) {
        int id = h(key);
        Node<T> *node = _table[id].next;
        while (node && node->key != key) {
            node = node->next;
        }

        if (node) {
            return node->data;
        } else {
            return flag;
        }
    }
};