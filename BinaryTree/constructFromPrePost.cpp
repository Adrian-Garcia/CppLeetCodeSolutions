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

void preOrder(TreeNode *r) {
	
	if (r != NULL) {
		cout << r->val << " ";
		preOrder(r->left);
		preOrder(r->right);
	}
}

void postOrder(TreeNode *r) {

	if (r != NULL) {
		postOrder(r->left);
		postOrder(r->right);
		cout << r->val << " ";
	}
}

void build(TreeNode *&r, vector<int>& pre, vector<int>& post, int &i, int &j, bool &finish) {

	cout << 2 << endl;

	if (finish)
		return;

	if (i == pre.size() || finish) {
		finish = true;
		return; 
	}

	if (pre[i] != post[j]) {

		r->left = new TreeNode(pre[i]);
		build(r->left, pre, post, i, j, finish);
		r->right = new TreeNode(pre[i]);
		i++;
		build(r->right, pre, post, i, j, finish);
		i++;
	}

	else {

		r->left = new TreeNode(pre[i]);
		i++; 
		j++;
	}
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

	cout << 1 << endl;

	int i=0;
	int j=0;

	TreeNode *root = new TreeNode(pre[i]);
	i++;

	bool finish = false;
	
	build(root, pre, post, i, j, finish);

	return root;
}

int main() {

	vector<int> pre;
	vector<int> post;
	TreeNode* root;

	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(5);
	pre.push_back(3);
	pre.push_back(6);
	pre.push_back(7);

	post.push_back(4);
	post.push_back(5);
	post.push_back(2);
	post.push_back(6);
	post.push_back(7);
	post.push_back(3);
	post.push_back(1);

	root = constructFromPrePost(pre, post);

	preOrder(root);
	postOrder(root);

	return 0;
}