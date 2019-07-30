/*
98. Validate Binary Search Tree 			Medium

	Given a binary tree, determine if it is a valid binary search tree (BST).

	Assume a BST is defined as follows:

		The left subtree of a node contains only nodes with keys less than the node's key.
		The right subtree of a node contains only nodes with keys greater than the node's key.
		Both the left and right subtrees must also be binary search trees.
 

	Example 1:

		    2
		   / \
		  1   3

		Input: [2,1,3]
		Output: true
	
	Example 2:

		    5
		   / \
		  1   4
		     / \
		    3   6

		Input: [5,1,4,null,null,3,6]
		Output: false
		
		Explanation: The root node's value is 5 but its right child's value is 4.
*/
#include <iostream>
#include <queue>

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

void inOrderNums(TreeNode* r, queue<int>& nums) {

	if (r != NULL) {

		inOrderNums(r->left, nums);
		nums.push(r->val);
		inOrderNums(r->right, nums);
	}
}

bool isValidBST(TreeNode* root) {

	if ((root->left == NULL && root->right == NULL) || root == NULL)
		return true; 

	queue<int> nums;
	int prev;
	inOrderNums(root, nums);

	prev = nums.front();
	nums.pop();

	while (!nums.empty()) {

		if (prev >= nums.front())
			return false; 

		prev = nums.front();
		nums.pop();
	}

	return true;
}

int main() {

	return 0;
}