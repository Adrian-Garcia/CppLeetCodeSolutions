/*
143. Reorder list 		Medium

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes 
itself may be changed.

Example 1:
	Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
	Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {

	stack s;
	queue q;

	ListNode *curr = head;
	ListNode *currFast = head;

	if (head != ) {


		while (currFast != NULL) {
			s.push(curr->val);
		}
	}

}

int main() {

	return 0;	
}