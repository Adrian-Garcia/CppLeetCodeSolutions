#include <iostream>
#include <stack>
#include <vector>

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

void preOrder(Node *root, int val, vector<int> thisPath, vector<int> &finalPath, bool &found) {

	if (root != NULL && !found) {

		thisPath.push_back(root->val);

		if (val == root->val) {

			for (int i=0; i<thisPath.size(); i++)
				finalPath.push_back(thisPath[i]);

			found = true;
		}

		else {
			preOrder(root->left, val, thisPath, finalPath, found);	
			preOrder(root->right, val, thisPath, finalPath, found);
		} 
	} 

}

Node* findCommonAncestor(Node *pRoot, Node *p1, Node *p2) {

	vector<int> path1;
	vector<int> path2;

	vector<int> aux1;
	vector<int> aux2;

	bool flag = false;

	preOrder(pRoot, p1->val, aux1, path1, flag);
	flag = false;
	preOrder(pRoot, p2->val, aux2, path2, flag);

	int limit = max(path1.size(), path2.size());
	int lastFather;

	for (int i=0; i<limit; i++) {

		if (path1[i] == path2[i])
			lastFather = path1[i];

		else
			break;
	}

	Node* a = new Node(lastFather);
	return a;
}


int main() {

	Node *root = new Node(5);

	add(root, 2);
	add(root, 1);
	add(root, 3);
	add(root, 7);
	add(root, 9);
	add(root, 6);

	Node* p1 = new Node(1);
	Node* p2 = new Node(3);

	Node* ancestor = findCommonAncestor(root, p1, p2);
	cout << endl << ancestor->val << endl;

	return 0;
}