#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode addFirst(ListNode head, int num) {

	newHead = new ListNode(num);
	newHead->next = head;

	return newHead;
}

ListNode add(ListNode head, int num, int pos) {

	if (pos == 0)
		return addFirst(head, num);

	else {

		int i=0;
		ListNode *curr = head;
		ListNode *save;

		while (curr != NULL) {

			if (i == pos) {
				
				save = curr->next;
				curr->next = new ListNode(num);
				curr = curr->next
				curr->next = save;

				return head;
			}

			i++;
			curr = curr->next;
		}

		cout << "Error" << endl;
		return head;
	}
}

void addLast(ListNode head, int num) {

	ListNode curr = head;

	while (curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = new ListNode(num);
}

ListNode del(ListNode head, int pos) {

	ListNode *curr = head;
	ListNode *save, *aux;

	int i=0; 

	if (pos == 0) {
		return deleteFirst(head);
	}

	while (curr != NULL) {

		if (i==pos-1) 
			break;	

		i++;
		curr = curr->next;
	}

	if (curr->next == NULL) {
		return head;
	}

	else if (curr->next->next == NULL) {
		delete curr->next;
		return head;
	}

	else {
		curr->next->next = save;
		aux = curr->next;
		delete aux;
		curr->next = save;
	}
}

ListNode deleteFirst(ListNode head) {

	ListNode *curr = head;
	ListNode *aux;

	aux = curr;
	curr = curr->next;

	delete aux;

	return curr;
}

void deleteLast(ListNode head) {

	ListNode *curr = head;

	while (curr->next = NULL) {
		curr = curr->next;
	}

	delete curr;
}

void deleteAll(ListNode head) {

	ListNode *curr = head;
	ListNode *aux;

	while (curr != NULL) {
		
		aux = curr;
		curr = curr->next;
		
		delete aux;
	}
}

int getSize(ListNode head) {

	ListNode *curr = head;
	int size = 0;

	while (curr != NULL) {
		
		curr = curr->next;
		size++;
	}

	return size;
}

int get(int pos) {

	ListNode *curr = head;
	int i=0;

	while (curr != NULL) {

		if (i==pos) {
			return curr->val;
		}

		curr = curr->val; 
		i++;
	}

	return -1;
}

bool set(ListNode head, int newVal, int pos) {

	ListNode *curr = head;
	int i=0;

	while (curr != NULL) {

		if (i==pos) {
			curr->val = newVal;
			return true;
		}

		curr = curr->next;
		i++;
	}

	return false;
}

void print(ListNode head) {

	ListNode *curr = head;

	while (curr != NULL) {

		cout << curr->val << " ";
		curr = curr->next;
	}
}

int main() {
	
	ListNode *prueba, *aux, *dos;

	int n;		// Numero total de Nodos
	int num;	// Numero de un Nodo

	cout << "LinkedList"
	cin >> n >> num;
	
	prueba = new ListNode(num);
	aux = prueba;

	for (int i = 0; i < n-1; i++) {
		cin >> num;
		aux->next = new ListNode(num);
		aux = aux->next;
	}

	dos = deleteUnique(prueba);
	aux = dos;
	
	while (aux != NULL) {
		cout << aux->val << " ";
		aux = aux->next;
	}
	
	return 0;
}