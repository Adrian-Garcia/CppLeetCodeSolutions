/*
2. Add Two numbers 		Medium

	You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their 
	nodes contain a single digit. Add the two numbers and return it as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Example:
		Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
		Output: 7 -> 0 -> 8
		Explanation: 342 + 465 = 807.

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	queue<int> list1;
	queue<int> list2;
	queue<int> list3;

	ListNode *curr1 = l1;
	ListNode *curr2 = l2;
	ListNode *curr3;

	unsigned long long int num1 = 0;
	unsigned long long int num2 = 0;
	unsigned long long int num3;

	unsigned long long int adder = 1;

	while (curr1 != NULL && curr2 != NULL) {
		
		list1.push(curr1->val);
		list2.push(curr2->val);

		curr1 = curr1->next;
		curr2 = curr2->next;
	}

	while (curr1 != NULL) {
		list1.push(curr1->val);
		curr1 = curr1->next;
	}

	while (curr2 != NULL) {
		list2.push(curr2->val);
		curr2 = curr2->next;
	}

	while (!list1.empty()) {
		num1 += adder * list1.front();
		adder*=10;
		list1.pop();
	}

	adder = 1;

	while (!list2.empty()) {
		num2 += adder * list2.front();
		adder*=10;
		list2.pop();
	}

	num3 = num1 + num2;

	if (num3 == 0) {
		list3.push(0);
	}
	
	else {
		
		while (num3 > 0) {
	
			list3.push(num3 % 10);
			num3/=10;
		}
		
	}
	
	ListNode *l3 = new ListNode(list3.front());
	curr3 = l3;
	list3.pop();

	while (!list3.empty()) {
	
		curr3->next = new ListNode(list3.front());
		curr3 = curr3->next;
		list3.pop();
	}

	return l3;
}	

void print(ListNode *head) {

	ListNode *curr = head;

	while (curr != NULL) {

		cout << curr->val << " ";
		curr = curr->next;
	}
}

int main() {
	
	ListNode *l1, *l2, *l3;
	ListNode *a1, *a2;

	cout << "addTwoNumbers" << endl;
	
	l1 = new ListNode(2);
	a1 = l1;
	a1->next = new ListNode(0);
	a1 = a1->next;
	a1->next = new ListNode(2);
	a1 = a1->next;

	l2 = new ListNode(1);
	a2 = l2;
	a2->next = new ListNode(0);
	a2 = a2->next;
	a2->next = new ListNode(3);
	a2 = a2->next;
	
	cout << "List1: ";
	print(l1);
	
	cout << "\nList2: ";
	print(l2);

	l3 = addTwoNumbers(l1, l2);
	cout << "\nSum: ";
	print(l3);

	return 0;
}
