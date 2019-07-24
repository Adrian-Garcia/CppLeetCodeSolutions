#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* delUnique(ListNode *head) {
	
	ListNode *curr = head;
	ListNode *prev, *aux;
	bool flag = false;
	bool first = true;
	int counter;

	if (curr->next == NULL) {
		delete curr;
		return NULL;
	}

	prev = curr;
	curr = curr->next;

	//Relocate head
	while (prev->val != curr->val && curr != NULL) {

		aux = prev;
		head = head->next;

		curr = curr->next;
		prev = prev->next;
		
		aux->next = NULL;
		delete aux;
	}

	while (curr != NULL) {

		if (prev->val == curr->val) {
			
			flag = false;
			first = true;

			aux = aux->next;
			curr = curr->next;
			prev = prev->next;

			continue;
			counter++;

		} else {
			flag = true;
		}

		if (flag) {
			
			if (curr->next->val == curr->val){
				flag = false;
				continue;
			}

			else {
				aux->next = prev->next;
				
				prev->next = NULL;
				delete prev;

				aux = aux->next;
				prev = aux->next;
				curr = curr->next;
			}
		}
	}

}

void print(ListNode *head) {

	ListNode *curr = head;

	while (curr != NULL) {

		cout << curr->val << " ";
		curr = curr->next;
	}
}


int main() {
	
	ListNode *head, *aux;

	int n;
	int num;

	cout << "LinkedList" << endl;
	
	head = new ListNode(0);
	aux = head;

	aux->next = new ListNode(1);
	aux = aux->next;
	aux->next = new ListNode(1);
	aux = aux->next;
	aux->next = new ListNode(2);
	aux = aux->next;
	aux->next = new ListNode(2);
	aux = aux->next;
	aux->next = new ListNode(3);
	aux = aux->next;
	aux->next = new ListNode(3);
	aux = aux->next;
	aux->next = new ListNode(4);
	aux = aux->next;
	aux->next = new ListNode(5);
	aux = aux->next;
	aux->next = new ListNode(5);
	aux = aux->next;
	
	print(head);
	head = delUnique(head);
	print(head);
	
	return 0;
}
