/*
671. Second Minimum Node In a Binary Tree 				Easy

	Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. 
	If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property 
	root.val = min(root.left.val, root.right.val) always holds.

	Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

	If no such second minimum value exists, output -1 instead.

	Example 1:

		Input: 
			    2
			   / \
			  2   5
			     / \
			    5   7

		Output: 5
		
		Explanation: The smallest value is 2, the second smallest value is 5.

	Example 2:

		Input: 
			    2
			   / \
			  2   2

		Output: -1
		
		Explanation: The smallest value is 2, but there isn't any second smallest value.
*/
#include <iostream>
#include <vector>

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

void path(TreeNode *r, vector<int> &arr, int &size, int &val, int &i) {

	if (r != NULL) {

		if (size < 2) {
			arr[i] = r->val;
			i++;
			size++;
		}

		else {
			if (r->val != arr[0] && r->val != arr[1]) {

				if (r->val < arr[1] && r->val > arr[0]) {
					arr[1] = r->val;
				}

				if (r->val < arr[0]) {
					arr[1] = arr[0];
					arr[0] = r->val;
				} 
			} 
		}

		path(r->left, arr, size, val, i);
		path(r->right, arr, size, val, i);
	}	
}


int findSecondMinimumValue(TreeNode* root) {
	
	if (root == NULL)
		return -1;

	if (root->left == NULL && root->right == NULL)
		return -1;

	vector<int> arr(2);
	int size = 0;
	int val;
	int i=0;

	path(root, arr, size, val, i);

	if (size < 2) 
		return -1;

	else
		return val;
}

int main() {

	return 0;
}