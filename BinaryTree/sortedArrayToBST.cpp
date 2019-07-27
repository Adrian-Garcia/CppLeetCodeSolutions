/*
108. Convert Sorted Array to Binary Search Tree 			Easy

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every 
node never differ by more than 1.

Example:
	
	Given the sorted array: [-10,-3,0,5,9],

	One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

	      0
	     / \
	   -3   9
	   /   /
	 -10  5

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

int main() {

	std::vector<char> v;

	for (int i=1; i<=5; i++)
		v.push_back(i);

	for (int i=0; i<v.size(); i++)
		cout << v << " ";

	return 0;
}