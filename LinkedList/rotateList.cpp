/*
61. Rotate List 			Medium

	Given a linked list, rotate the list to the right by k places, where k is non-negative.

	Example 1:

		Input: 1->2->3->4->5->NULL, k = 2
		Output: 4->5->1->2->3->NULL
		
		Explanation:
			rotate 1 steps to the right: 5->1->2->3->4->NULL
			rotate 2 steps to the right: 4->5->1->2->3->NULL

	Example 2:

		Input: 0->1->2->NULL, k = 4
		Output: 2->0->1->NULL
		
		Explanation:
			rotate 1 steps to the right: 2->0->1->NULL
			rotate 2 steps to the right: 1->2->0->NULL
			rotate 3 steps to the right: 0->1->2->NULL
			rotate 4 steps to the right: 2->0->1->NULL

*/
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {

	// End function if no need to move anything
	if (k == 0)
		return head; 

	ListNode *curr = head;
	ListNode *newHead;
	ListNode *aux;

	queue<int> nums;
	int size = 0;

	// Take Size of LinkedList
	while (curr != NULL) {	
		size++;
		curr = curr->next;
	}

	// Reduce k
	while (size > k) 
		k-=size;

	// End function if no need to move anything
	if (k == 0)
		return head; 

	// Go to the needed position
	curr = head;
	for (int i=0; i<size-k-1; i++) 
		curr = curr->next;

	// delete rest of linkedList
	aux = curr;
	curr = curr->next;
	aux->next = NULL;

	// push numbers back and delete unused linkedlist
	while (curr != NULL) {
		
		nums.push(curr->val)
		aux = curr;
		curr = curr->next;
		aux->next = NULL;
		delete aux;
	}

	// Create new LinkedList
	newHead = new ListNode(nums.front());
	curr = newHead;
	nums.pop();

	// Fill new LinkedList
	while (!nums.empty()) {
	
		curr->next = new ListNode(nums.front());
		curr = curr->next;
		nums.pop();
	}

	// Add new LinkedList to the old LinkedList
	curr->next = head;

	// Return the rotated LinkedList
	return newHead;
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

	cout << "Rotate List" << endl;

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
	head = rotateRight(head, 2);
	// cout << endl;
	// print (head);

	return 0;
}
