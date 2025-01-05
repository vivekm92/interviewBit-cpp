#include <iostream>
#include <stack>

using namespace std;

/*
	IB : https://www.interviewbit.com/problems/valid-bst-from-preorder/
	LC : https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description/
*/

/********************************************************************************/
// Optimised Approach 3:
// T(n) : O(n) ; S(n) : O(1)
int validBstFromPreorder2(vector<int>& A) {
	
	int n = A.size();
	if (n == 0) {
		return 1;
	}
	
	int i = 0, minLimit = INT_MIN;
	for (int &num : A) {
		while (i > 0 && num >= A[i-1]) {
			minLimit = A[i-1];
			i--;
		}
		
		if (num <= minLimit) {
			return 0;
		}
		
		A[i] = num;
		i++;
	}
	
	return 1;
}
/********************************************************************************/

// Optimised Approach 2:
// T(n) : O(n) ; S(n) : O(n)
int validBstFromPreorder1(vector<int>& A) {
	
	int n = A.size();
	if (n == 0) {
		return 1;
	}
	
	stack<int> st;
	int minVal = numeric_limits<int>::min();
	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top() <= A[i]) {
			minVal = st.top();
			st.pop();
		}
		
		if (minVal > A[i]) return 0;
		st.push(A[i]);
	}
	
	return 1;
}
/********************************************************************************/
 
struct node {
	int val;
	node *left, *right;
	node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Optimised Approach 1:
// T(n) : O(n) ; S(n) : O(n)
pair<node*, bool> validBstFromPreorderHelper(vector<int> &A, int start, int end, long lb, long ub) {
	if (start >= end) {
		return {nullptr, true};
	}

	node *n = new node(A[start]);
	if (n->val <= lb || n->val >= ub) {
		return {n, false};
	}
	
	int i = start + 1;
	while (i < end && A[start] > A[i]) {
		i++;
	}
	
	auto lp = validBstFromPreorderHelper(A, start + 1, i, lb, n->val);
	auto rp = validBstFromPreorderHelper(A,  i, end, n->val, ub);
	
	return {n, lp.second && rp.second};
}

int validBstFromPreorder(vector<int>& A) {
	auto p = validBstFromPreorderHelper(A, 0, A.size(), numeric_limits<long>::min(), numeric_limits<long>::max());
	return p.second ? 1 : 0; 
}
/********************************************************************************/

// Driver Code for testing
int main() {

    return 0;
}
