#include <iostream>
#include <vector>
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

vector<int> rightSideView(TreeNode* root) {

	vector<int> res;

	queue<TreeNode*> q;

	if (root == NULL)
		return res;

	q.push(root);

	int currLevel = 1;
	int nextLevel = 0;

	while (!q.empty()) {

		if (currLevel == 1)
			res.push_back(q.front()->val);

		if (q.front()->left != NULL) {
			q.push(q.front()->left);
			nextLevel++;
		}

		if (q.front()->right != NULL) {
			q.push(q.front()->right);
			nextLevel++;
		}

		currLevel--;

		if (currLevel == 0) {
			currLevel = nextLevel;
			nextLevel = 0;
		}

		q.pop();
	}

	return res;
}

int main() {

	TreeNode *cabecita = new TreeNode(5);

	add(cabecita, 2);
	add(cabecita, 3);
	add(cabecita, 1);
	add(cabecita, 8);
	add(cabecita, 7);
	add(cabecita, 6);

	vector<int> v = rightSideView(cabecita);

	for (int i=0; i<v.size(); i++)
		cout << v[i] << " ";

	return 0;
}