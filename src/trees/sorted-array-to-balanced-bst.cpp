#include <iostream>
#include "trees.h"

using namespace std;

/*
	IB : https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
	LC : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
*/

// Optimised Approach 1:
// T(n) : O(n) ; S(n) : O(n)
TreeNode* solveSortedArrayToBalancedBst(const vector<int>& A, int l, int r) {
	if (l > r) {
		return nullptr;
	}
	
	int m = l + (r - l) / 2;
	TreeNode *node = new TreeNode(A[m]);
	node->left = solveSortedArrayToBalancedBst(A, l, m - 1);
	node->right = solveSortedArrayToBalancedBst(A, m + 1, r);
	
	return node;
}

TreeNode* sortedArrayToBalancedBst(const vector<int>& A) {
	return solveSortedArrayToBalancedBst(A, 0, A.size() - 1);
}
/*************s*******************************************************************/

// Driver Code for testing
int main() {
	
	return 0;
}
