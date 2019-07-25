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
	print (head);

	return 0;
}
