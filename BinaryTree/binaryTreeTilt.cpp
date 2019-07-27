/*
563. Binary Tree Tilt 		Easy

	Given a binary tree, return the tilt of the whole tree.
	The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the 
	sum of all right subtree node values. Null node has tilt 0.

	The tilt of the whole tree is defined as the sum of all nodes' tilt.

	Example:
		
		Input: 
		         1
		       /   \
		      2     3
		
		Output: 1
			
		Explanation: 
			Tilt of node 2 : 0
			Tilt of node 3 : 0
			Tilt of node 1 : |2-3| = 1
			Tilt of binary tree : 0 + 0 + 1 = 1
	
	Note:
		
		The sum of node values in any subtree won't exceed the range of 32-bit integer.
		All the tilt values won't exceed the range of 32-bit integer.
*/
#include <iostream>
#include <queue>
#include <cstdlib>

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

void getTilt(TreeNode* r, int &sum) {

	if (r == NULL)
		return;

	getTilt(r->left, sum);

	int valLeft = (r->left != NULL) ?
		r->left->val : 0;

	int valRight = (r->right != NULL) ?
		r->right->val : 0;

	sum += abs(valLeft - valRight);

	getTilt(r->right, sum);
}

int findTilt(TreeNode* root) {
	
	int sum = 0;

	getTilt(root, sum);

	return sum;
}

int main () {

	TreeNode *root = new TreeNode(5);

	add(root, 2);
	add(root, 7);
	add(root, 1);
	add(root, 3);
	add(root, 8);
	add(root, 9);

	cout << findTilt(root) << endl;

	return 0;
}