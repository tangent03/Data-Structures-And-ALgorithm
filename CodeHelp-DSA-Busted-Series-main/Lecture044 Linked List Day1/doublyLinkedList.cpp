#include <bits/stdc++.h>
using namespace std;


//O(N);

class Node{
	public:
	int data;
	Node* prev;
	Node* next;
	
	
	Node(){
		this->prev = NULL;
		this->next = NULL;
	}
	
	Node(int data){
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};

void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data <<" ";
		temp = temp->next;
	}
}

int findLength(Node* &head){
	Node* temp = head;
	int length=0;
	while(temp != NULL){
		length++;
		temp=temp->next;
	}
	return length;
}

void insertAtHead(Node* &head, Node* &tail, int data){
	//LL is Empty
	if(head == NULL){
		Node* newNode = new Node(data);
		head =  newNode;
		tail = newNode;
	}
	else{
	//LL in Not Empty
		Node* newNode = new Node(data);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	
	
	
}

void insertAtTail(Node* &head, Node* &tail, int data){
	if(head == NULL){
		Node* newNode= new Node(data);
		head= newNode;
		tail= newNode;
	}
	else{
		Node* newNode = new Node(data);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

void insertAtPosition(Node* &head, Node* &tail , int data, int position){
	if(head == NULL){
		Node* newNode = new Node(data);
		head= newNode;
		tail= newNode;
	}
	else{
		int length = findLength(head);
		if(position == 1){
			insertAtHead(head,tail,data);
		}
		else if(position==length+1){
			insertAtTail(head,tail,data);
		}
		else{
			Node * newNode = new Node(data);
			Node* prevNode = NULL;
			Node* currNode = head;
			while(position!=1){
				position--;
				prevNode = currNode;
				currNode = currNode->next;
			}
			prevNode->next = newNode;
			newNode->prev= prevNode;
			newNode->next = currNode;
			currNode->prev = newNode;
		}
	}
}


void deleteNode(Node* &head, Node* &tail, int position){
	if(head==NULL){
		cout<<"cannot delete, its EMPLTY LL"<<endl;
		return;	
	}
	if(head==tail){
		Node*temp = head;
		delete temp;
		head=NULL;
		tail=NULL;
		return;
	}
	int length=findLength(head);
	if(position==1){
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		head->prev=NULL;
		delete temp;
	}
	else if(position==length){
		Node* prevNode = tail->prev;
		prevNode->next=NULL;
		tail->prev=NULL;
		delete tail;
		tail=prevNode;
	}
	else{
		//middle
		Node* prevNode=NULL;
		Node* currNode = head;
		while(position != 1){
			position--;
			prevNode=currNode;
			currNode = currNode->next;
		}
		Node* nextNode = currNode->next;
		
		
		prevNode->next=nextNode;
		currNode->prev=NULL;
		currNode->next =NULL;
		nextNode->prev=prevNode;
		
		delete currNode;
		
	}
}

int main(){
	
	//create NOde
	Node* head = NULL;
	Node* tail = NULL;
	insertAtHead(head,tail,40);
	insertAtHead(head,tail,30);
	insertAtHead(head,tail,20);
	insertAtHead(head,tail,10);
	print(head);
	cout<<endl;
	// insertAtTail(head,tail,1000);
	// print(head);
	
	// insertAtPosition(head,tail,1000,4);
	// print(head);
	
	deleteNode(head,tail,1);
	print(head);
	cout<<endl;
	deleteNode(head,tail,2);
	print(head);
	cout<<endl;
	deleteNode(head,tail,2);
	print(head);
	cout<<endl;
	// deleteNode(head,tail,1);
	// print(head);
	cout<<"Length of LL "<<findLength(head)<<endl;
	cout<<endl;
	deleteNode(head,tail,1);
	print(head);
	cout<<endl;
	cout<<"Length of LL "<<findLength(head)<<endl;
}