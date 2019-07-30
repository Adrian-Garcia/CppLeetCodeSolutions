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

void preOrder(TreeNode *r) {
	
	if (r != NULL) {
		cout << r->val << " ";
		preOrder(r->left);
		preOrder(r->right);
	}
}

void inOrder(TreeNode *r) {

	if (r != NULL) {
		inOrder(r->left);
		cout << r->val << " ";
		inOrder(r->right);
	}
}

void inOrderCounter(TreeNode *r, int k, int &counter, int &val, bool &flag) {

	if (r != NULL && !flag) {

		inOrderCounter(r->left, k, counter, val, flag);
		
		counter++;
		if (counter == k && !flag) {
			flag = true;
			val = r->val;
			return;
		}
		
		inOrderCounter(r->right, k, counter, val, flag);
	}
}

int kthSmallest(TreeNode* root, int k) {
	
	int val;
	int counter = 0;
	bool flag = false;

	inOrderCounter(root, k, counter, val, flag);

	return val;
}

int main() {

	TreeNode *root = new TreeNode(5);

	add(root, 3);
	add(root, 6);
	add(root, 2);
	add(root, 4);
	add(root, 1);

	// inOrder(root);

	cout << kthSmallest(root, 3) << endl;

	return 0;
}