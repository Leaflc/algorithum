//
// 二叉搜索树
// Created by leaflc on 2020/4/28.
//

#include <iostream>

using namespace std;

template<typename Key, typename Value>
class BinarySearchTree {

private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }

        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node root;
    int count;

public:
    BinarySearchTree() {
        root = NULL;
        count = 0;
    }

    ~BinarySearchTree() {
        destroy(root);
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

    bool contain(Key key) {
        return contain(root, key);
    }

    Value *search(Key key) {
        return search(root, key);
    }

    Key minimum() {
        assert(count != 0);
        Node *minNode = minimum(root);
        return minNode->key;
    }


    Key maximum() {
        assert(count != 0);
        Node *maxNode = maximum(root);
        return maxNode->key;
    }

    void removeMin() {
        if (root) {
            root = removeMin(root);
        }
    }

    void removeMax() {
        if (root) {
            root = removeMax(root);
        }
    }

    void remove(Key key) {
        remove(root, key);
//        removeInIteration(root,key);
    }


private:
    Node *insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }

        if (key == node->key) {
            node->value = value;
        } else if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }
        return node;
    }

    bool contain(Node *node, Key key) {
        if (node == NULL) return false;
        if (key == node->key) {
            return true;
        } else if (key < node->key) {
            return contain(node->left, key);
        } else {
            return contain(node->right, key);
        }
    }

    Value *search(Node *node, Key key) {
        if (node == NULL) {
            return NULL;
        }
        if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // 在以node为根的二叉搜索树中，返回最小键值的节点
    Node *minimum(Node *node) {
        if (node->left == NULL) {
            return node;
        }
        return minimum(node->left);
    }


    // 在以node为根的二叉搜索树中，返回最大键值的节点
    Node *maximum(Node *node) {
        if (node->right == NULL) {
            return node;
        }
        return maximum(node->right);
    }

    // 删除掉以node为根的二分搜索树中的最小结点
    // 返回删除结点后新的二分搜索树的根
    Node *removeMin(Node *node) {
        if (node->left == NULL) {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }


    // 删除掉以node为根的二分搜索树中的最大结点
    // 返回删除结点后新的二分搜索树的根
    Node *removeMax(Node *node) {
        if (node->right == NULL) {
            Node *leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }

        node->right = removeMax(node->right);
        return node;
    }


    // 删除掉以node为根的二分搜索树中键值为key的节点  递归方式
    // 返回删除节点后新的二分搜索树的根
    Node *remove(Node *node, Key key) {
        if (node == NULL)
            return NULL;

        if (key < node->key) {
            return node->left = remove(node->left);
        } else if (key > node->key) {
            return node->right = remove(node->right);
        } else {
            if (node->left == NULL) {
                Node *rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if (node->left == NULL) {
                Node *leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }

            // node->left != NULL && node->right != NULL
            Node *successor = new Node(minimum(node->right));
            count++;

            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            count--;

            return successor;

        }
    }


    // 删除指定结点非递归方式
    Node *removeInIteration(Node *node, Key key) {
        Node *current = node;  // 初始化指向根节点
        Node *pre = NULL;  // pre记录的是current的父节点
        while (current != NULL && current->key != key) {
            pre = next;
            if (current->key > key)
                current = current->right;
            else
                current = current->left;
        }
        if (current == NULL) return NULL;  // 没有找到

        if (current->left != NULL && current->right != NULL) {
            Node minCurrent = current->right;
            Node minPre = current;
            while (minCurrent.left != NULL) {
                minPre = minCurrent;
                minCurrent = minCurrent.left;
            }
            current->key = minPre.key;
            current->value = minPre.value;
            current = &minCurrent;
            pre = &minPre;
        }

        // 删除节点是叶子节点或者仅有一个子节点
        Node child;
        if (current->eft != NULL) {
            child = current->left;
        } else if (current->right != NULL) {
            child = current->right;
        } else
            child = NULL;

        if (pre == NULL) node = child; // 删除的是根节点 else if (pp.left == p) pp.left = child; else pp.right = child;
        else if (pre->left == current) pre->left = child;
        else pre->right = child;
        delete current;
        count--;
    }

    // 前序遍历
    void preOrder(Node *node) {
        if (node == NULL) return;
        cout << node->key << ":" << node->value << endl;
        preOrder(node->left);
        preOrder(node->right);
    }

    // 中序遍历
    void inOrder(Node *node) {
        if (node == NULL) return;
        inOrder(node->left);
        cout << node->key << ":" << node->value << endl;
        inOrder(node->right);
    }

    // 后序遍历
    void postOrder(Node *node) {
        if (node == NULL) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << ":" << node->value << endl;
    }


    // 通过后序遍历逐个删除树
    void destroy(Node *node) {
        if (node == NULL) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
        count--;
    }
};
