#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

class Node {
	public:
		int data;
		Node *next;

		Node() {
			next = NULL;
		};
		
		Node(int data) {
			this -> data = data;
			next = NULL;
		}

		
};

class List {
public:
	List() {}

	void insert(Node *head, int data);
	void printData(Node *head);
	void insertAtPosition(Node *head, int pos, int data);
	void deleteNode(Node *&head,int data);
};


void List::deleteNode(Node *&head,int data) {
	if(head == NULL) return;
	
	cout << "Inside Delete" << endl;
	if(head -> data == data) {
		Node *backUp = head;
		head = head -> next;
		free(backUp);
		return;
	}

	Node *temp = head;
	while(temp -> next &&  temp -> next -> data != data) {
		temp = temp -> next;
	}

	if(temp -> next == NULL) return;
	Node *backUp = temp -> next;
	temp -> next = temp -> next -> next;
	free(backUp);
}


void List::insert(Node *head, int data) {
	if(head == NULL) {
		head = new Node(data);
		return;
	}
		cout << "Inside Insert " << endl;
	Node *temp = head;
	while(temp -> next != NULL) temp = temp -> next;
	temp -> next = new Node(data);
}


void List::insertAtPosition(Node *head, int pos, int data) {
	if(pos < 0) return;

	Node *temp = head;
		cout << "Inside insertAtPosition" << endl;
	while(pos > 0) {
		temp = temp -> next;
		pos--;	
	}

	//Temp points to the pos now
	Node *backUp = temp -> next;
	Node *newNode = new Node(data);
	temp -> next = newNode;
	newNode -> next = backUp;
}



void List::printData(Node *head) {
	if(head == NULL) return;
	Node *temp = head;
	cout << "Data -> " << endl;
	while(temp) {
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
	cout << endl;
}


int main() {
	run();
	List singlyLinkedList;
	// cout << "List Data -> " << List.data << " Pointer ->" << List.next << endl;
	Node *head = new Node(10);
	singlyLinkedList.insert(head, 20);
	singlyLinkedList.insert(head, 30);
	singlyLinkedList.insertAtPosition(head, 1, 25);
	singlyLinkedList.deleteNode(head, 10);
	singlyLinkedList.printData(head);
	return 0;
}