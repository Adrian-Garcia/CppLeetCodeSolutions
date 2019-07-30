/*
230. Kth Smallest Element in a BST 				Medium

	Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

	Note: 
		You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

	Example 1:
	
		Input: root = [3,1,4,null,2], k = 1
		   3
		  / \
		 1   4
		  \
		   2
	
		Output: 1
	
	Example 2:
	
		Input: root = [5,3,6,2,4,null,null,1], k = 3
		       5
		      / \
		     3   6
		    / \
		   2   4
		  /
		 1
	
		Output: 3
	
	Follow up:
		What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
		How would you optimize the kthSmallest routine?
*/
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void add(TreeNode *root, int data) {

	TreeNode *curr = root;
	TreeNode *father = NULL;

	while (curr != NULL) {

		if (curr->val == data) 
			return;

		father = curr;

		curr = (data < curr->val) ?
			curr->left : curr->right; 
	}

	if (father->val > data) {
		father->left = new TreeNode(data);
	} else {
		father->right = new TreeNode(data);
	}
}

int main() {


	return 0;
}