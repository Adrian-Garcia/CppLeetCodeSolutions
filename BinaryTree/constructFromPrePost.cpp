/*
889. Construct Binary Tree from Preorder and Postorder Traversal 				Medium

	Return any binary tree that matches the given preorder and postorder traversals.
	Values in the traversals pre and post are distinct positive integers.

	Example 1:
		Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
		Output: [1,2,3,4,5,6,7]
	 
	Note:
		1 <= pre.length == post.length <= 30
		pre[] and post[] are both permutations of 1, 2, ..., pre.length.
		It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
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

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

}

int main() {

	return 0;
}