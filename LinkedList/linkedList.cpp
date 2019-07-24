#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addFirst(ListNode *head, int num) {

	ListNode *newHead = new ListNode(num);
	newHead->next = head;

	return newHead;
}

ListNode* add(ListNode *head, int num, int pos) {

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
				curr = curr->next;
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

void addLast(ListNode *head, int num) {

	ListNode *curr = head;

	while (curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = new ListNode(num);
}

ListNode* deleteFirst(ListNode *head) {

	ListNode *curr = head;
	ListNode *aux;

	aux = curr;
	curr = curr->next;

	delete aux;

	return curr;
}

ListNode* del(ListNode *head, int pos) {

	ListNode *curr = head;
	ListNode *save, *aux;
	
	int i=0; 
	bool found = false;

	if (pos == 0) {
		return deleteFirst(head);
	}
	
	aux = curr;
	curr = curr->next;
	i++;

	while (curr != NULL)  {

		if (i == pos) {
			found = true;
			break;	
		}

		i++;
		curr = curr->next;
		aux = aux->next;
	}

	if (!found)
		return head;

	else if (curr->next == NULL) {

		delete curr;
		return head;
	}
	
	else {
		
		aux->next = aux->next->next;
		delete curr;
		
		return head;
	}
}

ListNode* deleteLast(ListNode *head) {
	
	ListNode *curr = head;
	ListNode *last;
	
	while (curr->next != NULL) {
		last = curr;
		curr = curr->next;
	} 

	last->next = NULL;
	delete curr;
	return head;
}

void deleteAll(ListNode *head) {

	ListNode *curr = head;
	ListNode *prev;
	
	while(curr != NULL) {	
		prev = curr;
		curr = curr->next;
		delete prev;
		prev->next = NULL;
	}	
}

int getSize(ListNode *head) {

	ListNode *curr = head;
	int size = 0;

	while (curr != NULL) {
		
		curr = curr->next;
		size++;
	}
	
	return size;
}

int get(ListNode *head, int pos) {

	ListNode *curr = head;
	int i=0;

	while (curr != NULL) {

		if (i==pos) {
			return curr->val;
		}

		curr = curr->next; 
		i++;
	}

	return -1;
}

bool set(ListNode *head, int newVal, int pos) {

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

void print(ListNode *head) {

	ListNode *curr = head;

	while (curr != NULL) {

		cout << curr->val << " ";
		curr = curr->next;
	}
}

ListNode* delDuplicates(ListNode *head) {
	
	cout << endl;
	
	ListNode *curr = head;
	ListNode *prev = curr;
	ListNode *aux = head;
	int firstVal = curr->val;	
	bool flag = false;
	
	curr = curr->next;	
	while (firstVal == curr->val && curr->next != NULL) {
		
		head = head->next;
		delete aux;
		aux = head;
		
		prev = curr;
		curr = curr->next;
	}
	
	while (curr != NULL) {
		
		if (prev->val == curr->val) {
			prev->next = curr->next;
			aux = curr;
			curr = curr->next;
			delete aux;
			flag = true;
		}
		
		else {
			
			prev = curr;
			curr = curr->next;
		}
	}
	
	return head;
}

int main() {
	
	ListNode *head, *aux, *dos;

	int n;		// Numero total de Nodos
	int num;	// Numero de un Nodo

	cout << "LinkedList" << endl;
	cout << "Numero de Nodos: ";
	cin >> n;
	
	cout << "\nLinked List: ";
	cin >> num;
	
	head = new ListNode(num);
	aux = head;

	for (int i=0; i<n-1; i++) {
		cin >> num;
		aux->next = new ListNode(num);
		aux = aux->next;
	}
	
	print(head);
	head = delDuplicates(head);
	print(head);
	
	return 0;
}
