#pragma once
#include <iostream>

enum class TraverseOrder{
    PRE_ORDER,
    MID_ORDER
};

template <typename T> struct Node {
    int key;
    T data;
    Node *parent;
    Node *lChild;
    Node *rChild;
};

template <typename T> class BSTree {
private:
    Node<T> *root;

    Node<T> *minimumNode(Node<T> *node) {
        while (node->lChild) {
            node = node->lChild;
        }
        return node;
    }

    Node<T> *maxmumNode(Node<T> *node) {
        while (node->rChild) {
            node = node->rChild;
        }
        return node;
    }

    Node<T> *successor(Node<T> *node) {
        if (node->rChild) {
            return minimumNode(node->rChild);
        }
        Node<T> *suc = node->parent;
        while (suc && node == suc->rChild) {
            node = suc;
            suc = suc->parent;
        }
        return suc;
    }

    bool replace(Node<T> *n1, Node<T> *n2) { // use n2 replace n1
        if (n1->parent == NULL) {
            root = n2;
        } else if (n1 == n1->parent->lChild) {
            n1->parent->lChild = n2;
        } else {
            n1->parent->rChild = n2;
        }

        if (n2) {
            n2->parent = n1->parent;
        }
    }

    void release(Node<T> *node) {
        if (node) {
            release(node->lChild);
            release(node->rChild);
            delete node;
        }
    }

    // traverse the red-black tree
    void preTravese(Node<T> *node) {
        if (node) {
            std::cout<<node->key<<" ";
            preTravese(node->lChild);
            preTravese(node->rChild);
        }
    }

    void midTravese(Node<T> *node) {
        if (node) {
            midTravese(node->lChild);
            std::cout<<node->key<<" ";
            midTravese(node->rChild);
        }
    }
public:
    BSTree() {
        root = NULL;
    }
    ~BSTree() {
        release(root);
    }

    bool add(int key, T data) {
        Node<T> *pre = NULL;
        Node<T> *cur = root;
        while (cur) {
            pre = cur;
            if (key < cur->key) {
                cur = cur->lChild;
            } else if (key > cur->key) {
                cur = cur->rChild;
            } else { // should not exist 2 Nodes have the same key
                return false;
            }
        }

        Node<T> *newnode = new Node<T>();
        newnode->key = key;
        newnode->data = data;
        newnode->parent = pre;
        newnode->lChild = newnode->rChild = NULL;

        if (!pre) {
            root = newnode;
        } else if (pre->key < key) {
            pre->rChild = newnode;
        } else {
            pre->lChild = newnode;
        }

        return true;
    }

    bool remove(int key) {
        Node<T> *node = root;
        while (node && node->key != key) {
            if (key > node->key) {
                node = node->rChild;
            } else {
                node = node->lChild;
            }
        }
        if (!node) { // 
            return false;
        }

        if (!node->lChild) {
            replace(node, node->rChild);
            delete node;
        } else if (!node->rChild) {
            replace(node, node->lChild);
            delete node;
        } else {
            // find the successor of current node
            Node<T> *next = successor(node);

            if (next->parent != node) {
                replace(next, next->rChild);
                next->rChild = node->rChild;
                next->rChild->parent = next;
            }
            replace(node, next);
            next->lChild = node->lChild;
            next->lChild->parent = next;
            delete node;
        }
    }

    T find(int key, T flag) {
        Node<T> *node = root;
        while (node && node->key != key) {
            if (key > node->key) {
                node = node->rChild;
            } else {
                node = node->lChild;
            }
        }
        if (!node) {
            return flag;
        } else {
            return node->data;
        }
    }

    void traverse(TraverseOrder order = TraverseOrder::MID_ORDER) {
        switch (order) {
            case TraverseOrder::MID_ORDER: {
                midTravese(root);
                break;
            }
            case TraverseOrder::PRE_ORDER: {
                preTravese(root);
                break;
            }
        }
        std::cout<<std::endl;
    }
};