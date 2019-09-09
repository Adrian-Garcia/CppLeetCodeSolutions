#include <iostream>
#include <stack>

using namespace std;

struct Node {
	
	int val;
	Node* left;
	Node* right;

	Node(int x) : val(x), left(NULL), right(NULL){}

};

void add(Node *root, int data) {

	Node *curr = root;
	Node *father = NULL;

	while (curr != NULL) {

		if (curr->val == data) 
			return;

		father = curr;

		curr = (data < curr->val) ?
			curr->left : curr->right; 
	}

	if (father->val > data) {
		father->left = new Node(data);
	} else {
		father->right = new Node(data);
	}
}

void inOrder(Node *r) {

	if (r != NULL) {
		inOrder(r->left);
		cout << r->val << " ";
		inOrder(r->right);
	}
}

void preOrder(Node *root, int value1, int value2, bool& flag1, bool& flag2) {

	if (root == NULL || (flag1 && flag2))
		return;

	cout << root->val << endl; 

	if (value1 == root->val && !flag1)
		flag1 = true;

	if (value2 == root->val && !flag2)
		flag2 = true;

	preOrder(root->left, value1, value2, flag1, flag2);	
	preOrder(root->right, value1, value2, flag1, flag2);
}

Node* findCommonAncestor(Node *pRoot, Node *p1, Node *p2) {

	Node *father;

	bool flag1 = false;
	bool flag2 = false;

	stack<Node*> stk;

	stk.push(pRoot);

	while (!stk.empty()) {

		flag1 = false;
		flag2 = false;

		preOrder(stk.top(), p1->val, p2->val, flag1, flag2);

		if (flag1 && flag2) {
			
			father = stk.top();

			if (pRoot->left != NULL)
				stk.push(pRoot->left);

			if (pRoot->right != NULL)
				stk.push(pRoot->right);
		}

		stk.pop();
	}
}


int main() {

	Node *root = new Node(5);

	add(root, 2);
	add(root, 1);
	add(root, 3);
	add(root, 7);
	add(root, 9);
	add(root, 6);

	inOrder(root);

	Node* p1 = new Node(1);
	Node* p2 = new Node(7);

	Node* ancestor = findCommonAncestor(root, p1, p2);
	cout << endl << ancestor->val << endl;

	return 0;
}