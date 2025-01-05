#include <iostream>

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

template<typename T>
struct BinaryTreeNode {
    T data;
    std::unique_ptr<BinaryTreeNode<T> > left, right;
};

template <typename T>
struct BSTNode {
    T data;
    std::unique_ptr<BSTNode<T> > left, right;
};
