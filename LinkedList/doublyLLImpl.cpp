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
		Node *prev;
		Node() {
			next = NULL;
		};
		
		Node(int data) {
			this -> data = data;
			next = NULL;
			prev = NULL;
		}
};

class List {
public:
	List() {}

	void insert(Node *head, int data);
	void printData(Node *head);
	void insertAtBeginning(Node *&head, int data);
	void insertAtPosition(Node *head, int pos, int data);
	void deleteNode(Node *&head,int data);
};

void List::deleteNode(Node *&head,int data) {
	if(head == NULL) return;
	if(head -> data == data) {
		Node *backUp = head;
		head = head -> next;
		free(backUp);
		return;
	}
	Node *temp = head;
	while(temp && temp -> next -> data != data) {
		temp = temp -> next;
	}
	if(temp -> next == NULL) return;
	Node *backUp = temp -> next;
	temp -> next = backUp -> next;
	if(backUp -> next != NULL) {
		backUp -> next -> prev = temp;
	}
	free(backUp);
}

void List::insertAtBeginning(Node *&head, int data) {
	if(head == NULL) {
		head = new Node(data);
		return;
	}
	Node *newNode = new Node(data);
	newNode -> next = head;
	head -> prev = newNode;
	head = newNode;
}


void List::insert(Node *head, int data) {
	if(head == NULL) {
		head = new Node(data);
		return;
	}
	Node *temp =  head;
	while(temp -> next) {
		temp = temp -> next;
	}
	Node *newNode = new Node(data);
	temp -> next = newNode;
	newNode -> prev = temp;
}

void List::insertAtPosition(Node *head, int pos, int data) {
	if(pos < 0) return;
	Node *temp = head;
	while(pos > 0) {
		temp = temp -> next;
		pos--;	
	}
	Node *newNode = new Node(data);
	newNode -> next = temp -> next;
	newNode -> prev = temp;
	if(temp -> next == NULL) {
		temp -> next = newNode;
		return;
	}
	//Valid only if there is atleast 1 node ahead
	temp -> next -> prev = newNode;
	temp -> next = newNode;
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
	List doublyLL;
	Node *head = new Node(10);
	doublyLL.insert(head, 20);
	doublyLL.insert(head, 30);
	doublyLL.insert(head, 40);
	doublyLL.insertAtBeginning(head, 5);
	doublyLL.insertAtPosition(head, 4, 50);
	doublyLL.deleteNode(head, 5);
	doublyLL.insertAtPosition(head, 0, 15);
	doublyLL.printData(head);
	return 0;
}