#pragma once
#include <iostream>

using namespace std;

const bool RED = true;
const bool BLACK = false;

enum class TraverseOrder{
    PRE_ORDER,
    MID_ORDER
};

template <typename T> struct Node {
    int key;
    bool color; // true for red, false for black
    T data;
    Node *parent;
    Node *lChild;
    Node *rChild;
};

template <typename T> class RBTree {
private:
    Node<T> *root;
    Node<T> *nil;

    Node<T> *minimumNode(Node<T> *node) {
        while (node->lChild != nil) {
            node = node->lChild;
        }
        return node;
    }

    Node<T> *maxmumNode(Node<T> *node) {
        while (node->rChild != nil) {
            node = node->rChild;
        }
        return node;
    }

    void leftRotate(Node<T> *x) {
        // choose y
        Node<T> *y = x->rChild;
        // set y's lChild as x's rChild
        x->rChild = y->lChild;
        if (y->lChild != nil) {
            y->lChild->parent = x;
        }
        // y replace x
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->lChild) {
            x->parent->lChild = y;
        } else {
            x->parent->rChild = y;
        }
        y->parent = x->parent;
        // set x as y's lChild
        y->lChild = x;
        x->parent = y;
    }

    void rightRotate(Node<T> *x) {
        // choose y
        Node<T> *y = x->lChild;
        // set y's rChild as x's lChild
        x->lChild = y->rChild;
        if (y->rChild != nil) {
            y->rChild->parent = x;
        }
        // y replace x
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->lChild) {
            x->parent->lChild = y;
        } else {
            x->parent->rChild = y;
        }
        y->parent = x->parent;
        // set x as y's rChild
        y->rChild = x;
        x->parent = y;
    }

    void insertFixUp(Node<T> *x) {
        /* 
         * N stand for inserting/deleting Node
         * P stand for N's parent
         * U stand for N's uncle (P's brother)
         * G stand for N & U 's parent
         */

        // if P black, return(no need to fix)
        // if P red:
        while (x->parent->color == RED) {
            if (x->parent == x->parent->parent->lChild) {
                Node<T> *y = x->parent->parent->rChild;
                if (y->color == RED) { // case 1: P & U are red
                    // set P & U to black, and G to red
                    // in case G change to red break the rules
                    // set N to G, recursive fix
                    x->parent->color = BLACK;
                    y->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                } else {
                    if (x == x->parent->rChild) { // case 2: P red, U black, N at P right
                        x = x->parent; // after rotate, N become P's lChild, but N stand for P's child,
                                       // so before rotate, change N to P
                                       // change to case 3
                        leftRotate(x);
                    }
                    // case 3: P red, U black, N at P left
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    rightRotate(x->parent->parent);
                }
            } else { // P at G's right
                Node<T> *y = x->parent->parent->lChild;
                if (y->color == RED) {
                    x->parent->color = BLACK;
                    y->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                } else {
                    if (x == x->parent->lChild) {
                        x = x->parent;
                        rightRotate(x);
                    }
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    leftRotate(x->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void removeFixUp(Node<T> *n) {
        while (n != root && n->color == BLACK) {
            if (n == n->parent->lChild) { // N is P's lChild
                Node<T> *s = n->parent->rChild; // S: sibling(brother) of N
                if (s->color == RED) { // case 1: S is RED
                    s->color = BLACK;
                    n->parent->color = RED;
                    leftRotate(n->parent);
                    s = n->parent->rChild;
                }
                if (s->lChild->color == BLACK && s->rChild->color == BLACK) { // case 2: S is BLACK, it's children are BLACK
                    s->color = RED;
                    n = n->parent; // P's branch still 1 less black-height than it's sibling, so make N point to P
                                   // recursive fix up
                } else {
                    if (s->rChild->color == BLACK) { // case 3: S's rChild is BLACK, lChild is RED
                        s->lChild->color = BLACK;
                        s->color = RED; // change S and it's rChild's color
                        rightRotate(s);
                        s = n->parent->rChild; // turn into case 4
                    }
                    // case 4: S's lChild is BLACK, rChild is RED
                    s->color = n->parent->color;
                    n->parent->color = BLACK;
                    s->rChild->color = BLACK;
                    leftRotate(n->parent);
                    n = root;
                }
            } else { // N is P's rChild
                Node<T> *s = n->parent->lChild; // S: sibling(brother) of N
                if (s->color == RED) {
                    s->color = BLACK;
                    n->parent->color = RED;
                    rightRotate(n->parent);
                    s = n->parent->lChild;
                }
                if (s->lChild->color == BLACK && s->rChild->color == BLACK) {
                    s->color = RED;
                    n = n->parent;
                } else {
                    if (s->lChild->color == BLACK) { // case 3: S's lChild is BLACK, rChild is RED
                        s->rChild->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = n->parent->lChild;
                    }
                    // case 4: S's rChild is BLACK, lChild is RED
                    s->color = n->parent->color;
                    n->parent->color = BLACK;
                    s->lChild->color = BLACK;
                    rightRotate(n->parent);
                    n = root;
                }
            }
        }
        n->color = BLACK;
    }

    void transplant(Node<T> *x, Node<T> *y) {
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->lChild) {
            x->parent->lChild = y;
        } else {
            x->parent->rChild = y;
        }
        y->parent = x->parent;
    }

    void release(Node<T> *node) {
        if (node != nil) {
            release(node->lChild);
            release(node->rChild);
            delete node;
        }
    }

    // traverse the red-black tree
    void preTravese(Node<T> *node) {
        if (node != nil) {
            std::cout<<node->key<<" ";
            preTravese(node->lChild);
            preTravese(node->rChild);
        }
    }

    void midTravese(Node<T> *node) {
        if (node != nil) {
            midTravese(node->lChild);
            std::cout<<node->key<<" ";
            midTravese(node->rChild);
        }
    }
public:
    RBTree() {
        nil = new Node<T>();
        nil->color = BLACK;

        root = nil;
    }

    ~RBTree() {
        release(root);
        delete nil;
    }

    bool add(int key, T data) {
        Node<T> *pre = nil;
        Node<T> *cur = root;
        while (cur != nil) {
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
        newnode->parent = pre;
        newnode->lChild = newnode->rChild = nil;
        newnode->color = RED;
        newnode->data = data;

        if (pre == cur) {
            root = newnode;
        } else if (key > pre->key) {
            pre->rChild = newnode;
        } else {
            pre->lChild = newnode;
        }

        insertFixUp(newnode);
        return true;
    }

    bool remove(int key) {
        Node<T> *p = nil;
        Node<T> *n = root;
        while (n != nil && n->key != key) {
            p = n;
            if (key > n->key) {
                n = n->rChild;
            } else if (key < n->key) {
                n = n->lChild;
            }
        }
        if (n == nil) {
            return false;
        }
        
        //
        Node<T> *x; // record the node move to y
        Node<T> *y = n; // record N(N has 0 or 1 child) or the node transplant N(N has 2 children)
        bool yOriginColor = y->color;
        if (n->lChild == nil) { // N only has rChild
            x = n->rChild;
            transplant(n, n->rChild);
            delete n;
        } else if (n->rChild == nil) { // N only has lChild
            x = n->lChild;
            transplant(n, n->lChild);
            delete n;
        } else { // N has 2 children
            y = minimumNode(n->rChild); // y point to n's successor
            yOriginColor = y->color;
            x = y->rChild; // x may be nil
            if (y->parent == n) {
                x->parent = y;
            } else {
                transplant(y, y->rChild);
                y->rChild = n->rChild;
                y->rChild->parent = y;
            }
            transplant(n, y);
            y->lChild = n->lChild;
            y->lChild->parent = y;
            y->color = n->color;
            delete n;
        }
        if (yOriginColor == BLACK) { // if y were BLACK, x's brother's branch has 1 more black-height
                                     // so in this case need to fix up, reduce x's brother's branch's black-height
            removeFixUp(x);
        }

        return true;
    }

    T find(int key, T flag) {
        Node<T> *node = root;
        // int findCount = 0;
        while (node != nil && node->key != key) {
            if (key > node->key) {
                node = node->rChild;
            } else {
                node = node->lChild;
            }
            // ++findCount;
        }
        // std::cout<<"findCount="<<findCount<<std::endl;
        if (node == nil) {
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