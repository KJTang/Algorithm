#pragma once
#include <queue>
#include <iostream>

// #define DEBUG_MODE

using namespace std;

const int DEGREE = 5;
const int FLAG_COUNT = DEGREE/2;

template<typename T> struct DataNode {
    int key;
    T data;
};

template<typename T> struct TreeNode {
    int count;
    DataNode<T> *dataNodes[DEGREE];
    TreeNode *parent;
    TreeNode *children[DEGREE+1];
};

template<typename T> class BTree {
private:
    TreeNode<T> *root;
    int _height;

    TreeNode<T> *newTreeNode() {
        TreeNode<T> *temp = new TreeNode<T>();
        temp->count = 0;
        for (int i = 0; i != DEGREE; ++i) {
            temp->dataNodes[i] = NULL;
            temp->children[i] = NULL;
        }
        temp->children[DEGREE] = NULL;
        temp->parent = NULL;
        return temp;
    }

    TreeNode<T> *successor(TreeNode<T> *node, int id) {
        if (!node->children[id+1]) {
            return NULL;
        }
        TreeNode<T> *pre = node->children[id+1];
        TreeNode<T> *cur = node->children[id+1];
        while (cur) {
            pre = cur;
            cur = cur->children[0];
        }
        return pre;
    }

    void splitNode(TreeNode<T> *Left) {
        DataNode<T> *mid = Left->dataNodes[DEGREE/2];
        // Right       
        TreeNode<T> *Right = newTreeNode();
        for (int i = DEGREE/2+1, j = 0; i != DEGREE; ++i, ++j) {
            Right->dataNodes[j] = Left->dataNodes[i];
            ++Right->count;
        }
        for (int i = DEGREE/2+1, j = 0; i != DEGREE+1; ++i, ++j) {
            Right->children[j] = Left->children[i];
            if (Right->children[j]) {
                Right->children[j]->parent = Right;
            }
        }
        // Left
        for (int i = DEGREE/2; i != DEGREE; ++i) {
            Left->dataNodes[i] = NULL;
            Left->children[i+1] = NULL;
            --Left->count;
        }
        // Parent
        if (!Left->parent) {
            #ifdef DEBUG_MODE
            cout<<"[split]: new Root: "<<mid->key<<endl;
            #endif
            TreeNode<T> *Parent = newTreeNode();
            ++_height;
            
            Parent->count = 1;
            Parent->dataNodes[0] = mid;
            Parent->children[0] = Left;
            Parent->children[1] = Right;
            
            root = Parent;
            Left->parent = Parent;
            Right->parent = Parent;
        } else {
            //
            #ifdef DEBUG_MODE
            cout<<"[split]: old Root: "<<Left->parent->dataNodes[0]->key<<endl;
            #endif
            TreeNode<T> *Parent = Left->parent;
            int id = 0;
            while (Parent->children[id] != Left) {
                ++id;
            }
            // add TreeNode
            for (int i = Parent->count+1; i != id+1; --i) {
                Parent->children[i] = Parent->children[i-1];
            }
            Parent->children[id+1] = Right;
            Right->parent = Parent;
            // add DataNode
            for (int i = Parent->count; i != id; --i) {
                Parent->dataNodes[i] = Parent->dataNodes[i-1];
            }
            Parent->dataNodes[id] = mid;
            ++Parent->count;
            // if Parent 
            if (Parent->count == DEGREE) {
                splitNode(Parent);
            }
        }
    }

    void mergeNode(TreeNode<T> *Parent, int id) { // id marks the left node
        #ifdef DEBUG_MODE
        cout<<"[merge]"<<endl;
        #endif
        TreeNode<T> *Left = Parent->children[id];
        TreeNode<T> *Right = Parent->children[id+1];
        // get 1 node from parent
        Left->dataNodes[Left->count] = Parent->dataNodes[id];
        for (int i = id; i != Parent->count; ++i) {
            Parent->dataNodes[i] = Parent->dataNodes[i+1];
            Parent->children[i+1] = Parent->children[i+2];
        }
        ++Left->count;
        --Parent->count;
        // merge right node
        for (int i = 0; i != Right->count; ++i) {
            Left->dataNodes[Left->count+i] = Right->dataNodes[i];
        }
        for (int i = 0; i != Right->count+1; ++i) {
            Left->children[Left->count+i] = Right->children[i];
            if (Right->children[i]) {
                Right->children[i]->parent = Left;
            }
        }
        Left->count += Right->count;
        // delete right node
        delete Right;
    }

    void leftRotation(TreeNode<T> *Parent, int id) { // id marks the left node
        #ifdef DEBUG_MODE
        cout<<"[leftRotation]"<<endl;
        #endif
        TreeNode<T> *Left = Parent->children[id];
        TreeNode<T> *Right = Parent->children[id+1];
        // left node
        Left->dataNodes[Left->count] = Parent->dataNodes[id];
        Left->children[Left->count+1] = Right->children[0];
        if (Right->children[0]) {
            Right->children[0]->parent = Left;
        }
        ++Left->count;
        // parent node
        Parent->dataNodes[id] = Right->dataNodes[0];
        // right node
        for (int i = 0; i != Right->count; ++i) {
            Right->dataNodes[i] = Right->dataNodes[i+1];
        }
        for (int i = 0; i != Right->count+1; ++i) {
            Right->children[i] = Right->children[i+1];
        }
        --Right->count;
    }

    void rightRotation(TreeNode<T> *Parent, int id) { // id marks the left node
        #ifdef DEBUG_MODE
        cout<<"[rightRotation]"<<endl;
        #endif
        TreeNode<T> *Left = Parent->children[id];
        TreeNode<T> *Right = Parent->children[id+1];
        // right node
        for (int i = Right->count; i != 0; --i) {
            Right->dataNodes[i] = Right->dataNodes[i-1];
        }
        Right->dataNodes[0] = Parent->dataNodes[id];
        for (int i = Right->count+1; i != 0; --i) {
            Right->children[i] = Right->children[i-1];
        }
        Right->children[0] = Left->children[Left->count];
        if (Left->children[Left->count]) {
            Left->children[Left->count]->parent = Right;
        }
        ++Right->count;
        // parent node
        Parent->dataNodes[id] = Left->dataNodes[Left->count-1];
        // left node
        Left->dataNodes[Left->count-1] = NULL;
        Left->children[Left->count] = NULL;
        --Left->count;
    }

    void insertFixUp(TreeNode<T> *node) {
        // insertFixUp: split current node
        splitNode(node);
    }

    void removeFixUp(TreeNode<T> *node) {
        if (node->count >= FLAG_COUNT) {
            // case 1: node's count > FLAG_COUNT;
            // fix: none
            return;
        } else {
            // case 2: node's brother's count > FLAG_COUNT; 
            // fix: brother give 1 DataNode to parent, parent give 1 DataNode to node
            // case 3: node's brother's count <= FLAG_COUNT;
            // fix: merge node and it's brother, get 1 more DataNode from parent

            // find id
            if (!node->parent) {
                if (!node->count) {
                    root = node->children[0];
                    root->parent = NULL;
                    --_height;
                    delete node;
                }
                return;
            }
            int id = 0;
            while (node != node->parent->children[id]) {
                ++id;
            }
            // find brother
            TreeNode<T> *lBro = NULL;
            TreeNode<T> *rBro = NULL;
            TreeNode<T> *Parent = node->parent;

            lBro = (id == 0 ? NULL : Parent->children[id-1]);
            rBro = (id == Parent->count ? NULL : Parent->children[id+1]);

            if (!lBro) {
                if (node->count + rBro->count + 1 < DEGREE) {
                    mergeNode(Parent, id);
                    // incase parent break BTree rules
                    removeFixUp(Parent);
                } else {
                    leftRotation(Parent, id);
                }
            } else if (!rBro) {
                if (node->count + lBro->count + 1 < DEGREE) {
                    mergeNode(Parent, id-1);
                    removeFixUp(Parent);
                } else {
                    rightRotation(Parent, id-1);
                }
            } else {
                if (lBro->count > rBro->count) {
                    if (node->count + lBro->count + 1 < DEGREE) {
                        mergeNode(Parent, id);
                        removeFixUp(Parent);
                    } else {
                        rightRotation(Parent, id-1);
                    }
                } else {
                    if (node->count + rBro->count + 1 < DEGREE) {
                        mergeNode(Parent, id-1);
                        removeFixUp(Parent);
                    } else {
                        leftRotation(Parent, id);
                    }
                }
            }
        }
    }

    void releaseNode(TreeNode<T> *node) {
        if (node) {
            for (int i = 0; i != node->count; ++i) {
                delete node->dataNodes[i];
            }
            for (int i = 0; i != node->count+1; ++i) {
                releaseNode(node->children[i]);
            }
            delete node;
        }
    }

    void printNode(TreeNode<T> *node) {
        for (int i = 0; i != node->count; ++i) {
            cout<<node->dataNodes[i]->key<<" ";
        }
        cout<<"| parent="<<(node->parent?node->parent->dataNodes[0]->key:-1)<<" count="<<node->count<<endl;
    }
public:
    BTree() {
        root = NULL;
        _height = 0;
    }
    ~BTree() {
        releaseNode(root);
    }

    bool insert(int key, T data) {
        #ifdef DEBUG_MODE
        cout<<"[insert]: "<<key<<endl;
        #endif
        TreeNode<T> *pre = root;
        TreeNode<T> *cur = root;

        while (cur) {
            pre = cur;
            for (int i = 0; i != cur->count; ++i) {
                if (key < cur->dataNodes[i]->key) {
                    cur = cur->children[i];
                    break;
                } else if (key > cur->dataNodes[i]->key) {
                    if (i == cur->count-1) {
                        cur = cur->children[cur->count];
                        break;
                    } else {
                        continue;
                    }
                } else {
                    return false;
                }
            }
        }

        DataNode<T> *newnode = new DataNode<T>();
        newnode->key = key;
        newnode->data = data;

        if (!pre) {
            root = newTreeNode();
            ++_height;
            root->count = 1;
            root->dataNodes[0] = newnode;
        } else {
            // find insert position
            int id = 0;
            while (id != pre->count && key > pre->dataNodes[id]->key) {
                ++id;
            }
            // insert new DataNode to position
            for (int i = pre->count; i != id; --i) {
                pre->dataNodes[i] = pre->dataNodes[i-1];
            }
            pre->dataNodes[id] = newnode;
            ++pre->count;
            // fix up (make current tree transfer to a BTree)   
            if (pre->count == DEGREE) {
                insertFixUp(pre);
            }
        }

        return true;
    }

    bool remove(int key) {
        #ifdef DEBUG_MODE
        cout<<"[remove]: "<<key<<endl;
        #endif
        TreeNode<T> *pre = root;
        TreeNode<T> *cur = root;
        int id = -1;

        while (cur) {
            pre = cur;
            for (int i = 0; i != cur->count; ++i) {
                if (key < cur->dataNodes[i]->key) {
                    cur = cur->children[i];
                    break;
                } else if (key > cur->dataNodes[i]->key) {
                    if (i == cur->count-1) {
                        cur = cur->children[i+1];
                        break;
                    } else {
                        continue;
                    }
                } else {
                    id = i;
                    cur = NULL; // break the while-loop
                    break;
                }
            }
        }

        if (id == -1 || !pre) {
            #ifdef DEBUG_MODE
            cout<<"[remove]: failed"<<endl;
            #endif
            return false;
        }
        // cout<<"[remove]: ["<<pre->dataNodes[id]->key<<"]"<<endl;

        // delete node
        TreeNode<T> *node = pre; // rename
        TreeNode<T> *suc = successor(node, id);
        if (suc) {
            delete node->dataNodes[id];
            node->dataNodes[id] = suc->dataNodes[0];
            for (int i = 0; i != suc->count; ++i) {
                suc->dataNodes[i] = suc->dataNodes[i+1];
            }
            --suc->count;
            node = suc;
        } else {
            delete node->dataNodes[id];
            for (int i = id; i != node->count; ++i) {
                node->dataNodes[i] = node->dataNodes[i+1];
            }
            --node->count;
        }
        // fix up (make current tree transfer to a BTree)
        removeFixUp(node);
        return true;
    }

    T find(int key, T &flag) {
        return flag;
    }

    void traverse() {
        cout<<"------------Traverse Start--------------"<<endl;
        std::queue<TreeNode<T>*> queue;
        if (root) {
            queue.push(root);
        }
        for (int i = 0; i != _height; ++i) {
            cout<<"Layer "<<i+1<<endl;
            int len = queue.size();
            for (int j = 0; j != len; ++j) {
                printNode(queue.front());
                for (int k = 0; k != queue.front()->count+1; ++k) {
                    queue.push(queue.front()->children[k]);
                }
                queue.pop();
            }
        }
        cout<<"------------Traverse End----------------"<<endl;
    }
};