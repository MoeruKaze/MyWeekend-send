#pragma once
#include <iostream>

template <typename T>
class TreeNode 
{
public:
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    bool isRed;
    T value;

    TreeNode();
    TreeNode(T value);
    TreeNode(const TreeNode& other);
    ~TreeNode();
};

template <typename T>
TreeNode<T>::TreeNode() 
{
    this->value = T();
    this->isRed = false;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template <typename T>
TreeNode<T>::TreeNode(T value) 
{
    this->value = value;
    this->isRed = true;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template <typename T>
TreeNode<T>::TreeNode(const TreeNode& other) 
{
    this->value = other.value;
    this->isRed = other.isRed;
    this->left = other.left;
    this->right = other.right;
    this->parent = other.parent;
}

template <typename T>
TreeNode<T>::~TreeNode() 
{

}
