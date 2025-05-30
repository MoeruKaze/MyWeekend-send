#pragma once
#include "TreeNode.h"

template <typename T>
class RedBlackTree 
{
public:
    TreeNode<T>* root;
    TreeNode<T>* empty;

    RedBlackTree();
    RedBlackTree(const RedBlackTree& other);
    ~RedBlackTree();
    RedBlackTree& operator=(const RedBlackTree& other);

    void add(const T& value);
    bool find(const T& value) ;

    friend std::ostream& operator<<(std::ostream& os, const RedBlackTree& tree) {
        tree.recursivePrint(os, tree.root, "", false);
        return os;
    }

private:
    void correctInsert(TreeNode<T>* node);
    void rightRotate(TreeNode<T>* node);
    void leftRotate(TreeNode<T>* node);
    void recursivePrint(std::ostream& os, TreeNode<T>* node, const std::string& prefix, bool isLeft) const;
    void copyTree(TreeNode<T>*& newNode, const TreeNode<T>* otherNode, TreeNode<T>* parent);
    void clearTree(TreeNode<T>* node);
    TreeNode<T>* findMin(TreeNode<T>* node) const;
};

template <typename T>
RedBlackTree<T>::RedBlackTree() {
    empty = new TreeNode<T>();
    empty->isRed = false;
    root = empty;
}

template <typename T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree& other) {
    empty = new TreeNode<T>();
    empty->isRed = false;
    root = empty;
    if (other.root != other.empty) {
        copyTree(root, other.root, nullptr);
    }
}

template <typename T>
RedBlackTree<T>::~RedBlackTree() {
    clearTree(root);
    delete empty;
}

template <typename T>
RedBlackTree<T>& RedBlackTree<T>::operator=(const RedBlackTree& other) {
    if (this != &other) {
        clearTree(root);
        copyTree(root, other.root, nullptr);
    }
    return *this;
}

template <typename T>
void RedBlackTree<T>::add(const T& value) {
    TreeNode<T>* newNode = new TreeNode<T>(value);
    newNode->left = empty;
    newNode->right = empty;

    TreeNode<T>* parent = nullptr;
    TreeNode<T>* current = root;

    while (current != empty) {
        parent = current;
        if (newNode->value < current->value) {
            current = current->left;
        }
        else if (newNode->value > current->value) {
            current = current->right;
        }
        else {
            delete newNode;
            return;
        }
    }

    newNode->parent = parent;

    if (parent == nullptr) {
        root = newNode;
    }
    else if (newNode->value < parent->value) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    if (newNode->parent == nullptr) {
        newNode->isRed = false;
        return;
    }

    if (newNode->parent->parent == nullptr) {
        return;
    }

    correctInsert(newNode);
}

template <typename T>
bool RedBlackTree<T>::find(const T& constValue)  {
    TreeNode<T>* current = root;
    T value = constValue;
    while (current != empty) {
        if (value == current->value) {
            return true;
        }
        else if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

template <typename T>
void RedBlackTree<T>::correctInsert(TreeNode<T>* node) {
    while (node != root && node->parent->isRed) {
        if (node->parent == node->parent->parent->left) {
            TreeNode<T>* uncle = node->parent->parent->right;
            if (uncle->isRed) {
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                rightRotate(node->parent->parent);
            }
        }
        else {
            TreeNode<T>* uncle = node->parent->parent->left;
            if (uncle->isRed) {
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                leftRotate(node->parent->parent);
            }
        }
    }
    root->isRed = false;
}

template <typename T>
void RedBlackTree<T>::rightRotate(TreeNode<T>* node) {
    TreeNode<T>* tmp = node->left;
    node->left = tmp->right;
    if (tmp->right != empty) {
        tmp->right->parent = node;
    }
    tmp->parent = node->parent;
    if (node->parent == nullptr) {
        root = tmp;
    }
    else if (node == node->parent->right) {
        node->parent->right = tmp;
    }
    else {
        node->parent->left = tmp;
    }
    tmp->right = node;
    node->parent = tmp;
}

template <typename T>
void RedBlackTree<T>::leftRotate(TreeNode<T>* node) {
    TreeNode<T>* tmp = node->right;
    node->right = tmp->left;
    if (tmp->left != empty) {
        tmp->left->parent = node;
    }
    tmp->parent = node->parent;
    if (node->parent == nullptr) {
        root = tmp;
    }
    else if (node == node->parent->left) {
        node->parent->left = tmp;
    }
    else {
        node->parent->right = tmp;
    }
    tmp->left = node;
    node->parent = tmp;
}

template <typename T>
void RedBlackTree<T>::recursivePrint(std::ostream& os, TreeNode<T>* node, const std::string& prefix, bool isLeft) const {
    if (node != empty) {
        os << prefix;
        os << (isLeft ? "|-- " : "|-- ");
        os << node->value << (node->isRed ? " (R)" : " (B)") << std::endl;
        recursivePrint(os, node->right, prefix + (isLeft ? "   " : "    "), true);
        recursivePrint(os, node->left, prefix + (isLeft ? "    " : "    "), false);
    }
}

template <typename T>
void RedBlackTree<T>::copyTree(TreeNode<T>*& newNode, const TreeNode<T>* otherNode, TreeNode<T>* parent) {
    if (otherNode == nullptr || otherNode->left == nullptr) {
        newNode = empty;
        return;
    }

    newNode = new TreeNode<T>(otherNode->value);
    newNode->isRed = otherNode->isRed;
    newNode->parent = parent;

    copyTree(newNode->left, otherNode->left, newNode);
    copyTree(newNode->right, otherNode->right, newNode);
}

template <typename T>
void RedBlackTree<T>::clearTree(TreeNode<T>* node) {
    if (node != empty && node != nullptr) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

template <typename T>
TreeNode<T>* RedBlackTree<T>::findMin(TreeNode<T>* node) const {
    while (node->left != empty) {
        node = node->left;
    }
    return node;
}