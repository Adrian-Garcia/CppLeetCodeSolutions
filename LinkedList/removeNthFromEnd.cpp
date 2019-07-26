/*
19. Remove Nth Node From End of List 					Medium

	Given a linked list, remove the n-th node from the end of list and return its head.

	Example:
		Given linked list: 1->2->3->4->5, and n = 2.
		After removing the second node from the end, the linked list becomes 1->2->3->5.

	Note:
		Given n will always be valid.

	Follow up:
		Could you do this in one pass?
*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

	if (n == 0)
		return head;

	ListNode *curr = head;
	ListNode *aux;
	int count = 0;

	while (curr != NULL) {
		count++;
		curr = curr->next;
	}

	curr = head;

	if (n >= count) {

		aux = head;
		head = head->next;
		aux->next = NULL;
		delete aux;

	} else {

		for (int i=0; i<count-n-1; i++) 
			curr = curr->next;

		aux = curr->next;
		curr->next = curr->next->next;
		aux->next = NULL;
		delete aux;
	}

	return head;
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

	cout << "Remove Nth Node From End of List" << endl;

	head = new ListNode(1);
	aux = head;

	aux->next = new ListNode(2);
	aux = aux->next;
	aux->next = new ListNode(3);
	aux = aux->next;
	aux->next = new ListNode(4);
	aux = aux->next;
	aux->next = new ListNode(5);
	aux = aux->next;

	print(head);
	head = removeNthFromEnd(head, 2);
	cout << endl;
	print (head);

	return 0;
}
