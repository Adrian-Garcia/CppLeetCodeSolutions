/*
100. Same Tree 				Easy

	Given two binary trees, write a function to check if they are the same or not.
	Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:
	
	Input:     1         1
	          / \       / \
	         2   3     2   3

	        [1,2,3],   [1,2,3]

	Output: true

Example 2:

	Input:     1         1
	          /           \
	         2             2

	        [1,2],     [1,null,2]

	Output: false

Example 3:

	Input:     1         1
	          / \       / \
	         2   1     1   2

	        [1,2,1],   [1,1,2]

	Output: false
*/

#include <iostream>
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

void validateTrees(TreeNode* p, TreeNode* q, bool &flag) {

	if (p == NULL && q == NULL)
		return; 

	if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
		flag = false;
		return;
	}

	if (p->val != q->val) {
		flag = false;
		return;
	}

	validateTrees(p->left, q->left, flag);
	validateTrees(p->right, q->right, flag);
}

bool isSameTree(TreeNode* p, TreeNode* q) {

	bool flag = true;
	validateTrees(p, q, flag);
	return flag;
}

int main() {

	TreeNode *p = new TreeNode(5);
	TreeNode *q = new TreeNode(5);

	add(p, 2);
	add(q, 2);

	add(p, 5);
	add(q, 1);

	add(p, 3);
	add(q, 3);

	add(p, 7);
	add(q, 7);

	add(p, 9);
	add(q, 9);

	add(p, 8);
	add(q, 8);

	add(p, 4);
	add(q, 4);

	bool flag = isSameTree(p, q);

	if (flag)
		cout << "Fer me caso contigo si es verdadero";
	else
		cout << "Chale";

	return 0;
}