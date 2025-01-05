#include <iostream>
#include <queue>
#include "trees.h"

using namespace std;

/*
    IB : https://www.interviewbit.com/problems/valid-binary-search-tree/
    LC : https://leetcode.com/problems/validate-binary-search-tree/description/
*/

/********************************************************************************/
struct node {
    TreeNode* A;
    long lb, ub;
    node(TreeNode* B): A(B), lb(numeric_limits<long>::min()), ub(numeric_limits<long>::max()) {}
};

// Optimised Approach 3:
// T(n) : O(n) ; S(n) : O(h), n -> number of nodes, h -> height of tree
int validBinarySearchTree2(TreeNode *A) {

    queue<node* > q;
    node *n = new node(A);

    q.push(n);
    while (!q.empty()) {
        n = q.front();
        if (n->A->val <= n->lb || n->A->val >= n->ub) {
            return 0;
        }
        q.pop();
        if (n->A->left != nullptr) {
            node *n1 = new node(n->A->left);
            n1->ub = n->A->val;
            n1->lb = n->lb;
            q.push(n1);
        }

        if (n->A->right != nullptr) {
            node *n2 = new node(n->A->right);
            n2->lb = n->A->val;
            n2->ub = n->ub;
            q.push(n2);
        }
    }

    return 1;
}
/********************************************************************************/

// Optimised Approach 2:
// T(n) : O(n) ; S(n) : O(h), n -> number of nodes, h -> height of tree
int solveValidBinarySearchTree1(TreeNode *A, long minVal, long maxVal) {
    if (A == nullptr) {
        return 1;
    }

    if (A->val <= minVal || A->val >= maxVal) {
        return 0;
    }

    return solveValidBinarySearchTree1(A->left, minVal, (int )A->val) && 
        solveValidBinarySearchTree1(A->right, (int )A->val, maxVal);
}

int validBinarySearchTree1(TreeNode *A) {
    return solveValidBinarySearchTree1(A, numeric_limits<long>::min(), numeric_limits<long>::max());
}
/********************************************************************************/

// Optimised Approach 1:
// T(n) : O(n) ; S(n) : O(h), n -> number of nodes, h -> height of tree
int solveValidBinarySearchTree(TreeNode *A, int *minVal, int *maxVal) {
    
    if (A == nullptr) {
        return 1;
    }

    if (minVal != nullptr && A->val <= *minVal || maxVal != nullptr && A->val >= *maxVal) {
        return 0;
    }

    return solveValidBinarySearchTree(A->left, minVal, &(A->val)) && 
        solveValidBinarySearchTree(A->right, &(A->val), maxVal);
}

int validBinarySearchTree(TreeNode *A) {
    return solveValidBinarySearchTree(A, nullptr, nullptr);
}
/********************************************************************************/

// Driver Code for testing
int main() {


    return 0;
}
