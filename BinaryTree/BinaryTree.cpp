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

bool search(TreeNode *root, int data) {

	TreeNode *curr = root;

	while (curr != NULL) {

		if (curr-> val == data)
			return true;

		curr = (curr->val > data) ?
			curr->left : curr->right;
	}

	return false;

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

void postOrder(TreeNode *r) {

	if (r != NULL) {
		postOrder(r->left);
		postOrder(r->right);
		cout << r->val << " ";
	}
}

void levels(TreeNode *root) {

	queue<TreeNode*> nodes;

	nodes.push(root);

	while (!nodes.empty()) {

		if (nodes.front()->left != NULL)
			nodes.push(nodes.front()->left);

		if (nodes.front()->right != NULL)
			nodes.push(nodes.front()->right);

		cout << nodes.front()->val << " ";

		nodes.pop();
	}
}

int whatLevelAmI(TreeNode *root, int data) {

	TreeNode *curr = root;
	int level = 0;

	while (curr != NULL) {

		if (curr->val == data)
			return level;

		curr = (curr->val > data) ?
			curr->left : curr->right;

		level++;
	}

	return -1;
}

int height(TreeNode *r) {

	if (r == NULL) 
		return 0;

	int left = height(r->left);
	int right = height(r->right);

	return 1 + (left > right ? left : right);
}

int main() {

	TreeNode *root = new TreeNode(5);

	add(root, 2);
	add(root, 4);
	add(root, 7);
	add(root, 9);
	add(root, 6);
	add(root, 1);
	add(root, 0);
	add(root, 8);
	add(root, 1);

	cout << search(root, 0) << endl;
	cout << whatLevelAmI(root, 9) << endl;
	cout << height(root) << endl;
	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	levels(root);

	return 0;
}