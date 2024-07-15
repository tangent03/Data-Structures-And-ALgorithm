#include <bits/stdc++.h>
using namespace std;

// OS ME STORAGE MANAGEMENT ME LINKED LIST KAHAN USE HOTA HAI?

//CREATING NODE

//use of constructor -object of initailise krne ke lie use hota hai


//TIME COMPLEXITY = O(N);
 
 class Node{
 	public:
 	int data;
 	Node* next; //pointer to next node (pointer(next) to node)
 	//constructor 
 	
 	//jab koi data nahi dalenege to esa node.
 	Node(){
 		cout<<"I am inside default Constructor";
 		this->next = NULL;
 	}
 	
 	//jab data dalenge to esa node banega;
 	Node(int data){
 		cout<<"I am inside Param Constructor"<<endl;
 		this->data=data;
 		this->next=NULL;
 	}
 	~Node(){
 		cout<<"Destructor Called For"<<this->data<<endl;
 	}
 	
 };
 
 
 //first node - HEAD
 //last node - TAIL
 void printLinkedList(Node* head){
 	Node* temp = head;
 	
 	while(temp!=NULL){
 		cout<<temp->data<<" ";
 		temp = temp->next;
 	}
 	cout<<endl;
 }


int getLength(Node* head){
	Node* temp = head;
	int count=0;
	
	while(temp!= NULL){
		count++;
		temp=temp->next;
	}
	return count;
	
}


void insertAtHead(Node* &head, Node* &tail,int data){
	
	if(head==NULL){
		//empty LL
		Node* newNode = new Node(data);
		head=newNode;
		tail=newNode;
	}
	else{
		//create new node
	Node* newNode= new Node(data);
	
	//point the newNode->next to head
	newNode->next = head;
	
	//head ko newNode pe le jao
	head = newNode;
		
	}
	
}


void insertAtTail(Node* &head, Node* &tail, int data){
	if(head==NULL){
		Node* newNode = new Node(data);
		//single hai islie head aur tail dono pe newNode;
		head=newNode;
		tail=newNode;
		
	}
	
	else{
		//craete a newNode
	Node* newNode = new Node(data);
	
	//point the tail to newNode
	tail->next=newNode;
	//tail ko new Node pe le jao
	tail=newNode;
		
	}
	
}


void insertAtPosition(Node* &head, Node* &tail, int data, int position){
	
	int length = getLength(head);
	
	
	 
	 if(position <= 1){
	 	insertAtHead(head,tail,data);
	 }
	 else if(position > length){
	 	insertAtTail(head,tail,data);
	 }
	 else{
	 	//create a node
	 	Node* newNode = new Node(data);
	 	
	 	//traverse prev and curr to position;
	 	
	 	Node* prev = NULL;
	 	Node* curr = head;
	 	
	 	while(position != 1){
	 		prev=curr;
	 		curr=curr->next;
	 		position--;
	 	}
	 	
	 	//attach prev to new Node
	 	prev->next = newNode;
	 	
	 	
	 	//attach newNode to curr
	 	newNode ->next =curr;
	 }
}









//--------------------------------------------------------------------------------




void deleteNode(Node* &head, Node* &tail,int position){
	
	int length = getLength(head);
	//empty list
	if(head==NULL){
		cout<<"Cannot Delete , Becaouse Linked List is Empty "<<endl;
		return;
	}
	if(head==tail){
		//single element
		Node* temp = head;
		delete temp;
		head=NULL;
		tail=NULL;
		returnu
	}
	
	//delete from Head
	if(position==1){
		//first node ko delete kro
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp; // dynamical ko deelte krne se destructor call hota hai
	}
	else if(position==length){
	 //last node ko delete kro
	 
	 //find prev
	 Node* prev = head;
	 while(prev->next !=tail){
	 	prev=prev->next;
	 }
	 
	 //prev node ka link NULL karo
	 prev->next=NULL;
	 
	 //node deldete kro
	 delete tail;
	 
	 //update tail
	 tail=prev;
	 
	  
	 
	}
	else{
		//middle me koi node delete kro
		//set prev and curr
		Node* prev = NULL;
		Node* curr = head;
		while(position!=1){
			position--;
			prev =curr;
			curr=curr->next;
		}
		
		//prev->next ko curr ke aage lagao
		
		prev->next = curr->next;
		
		//curr ka neext htao
		curr->next = NULL;
		//delete curr
		delete curr;
	}
	
}











int main(){
	
	//Creation of Node
	
	
	
	//static allocation of object
	// Node a;
	
	//dynamic allocation 
	// Node* Head = new Node();
	
	//dono case me constructor call hota hai.
	
	
	//isse nodes bane hai (dabbe)
	//and we know Linked List is Collection Of Nodes;
	Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);
	Node* fourth = new Node(40);
	Node* fifth = new Node(50);
	
	
	//isse Nodes Connect hue hai
	//basically First node ka jo next wala part hai vo Pure second ko point krra hai
	first->next = second;
	second->next =third;
	third->next =fourth;
	fourth->next=fifth;
	
	//linked list ban chuki hai
	
	
	Node* head = first;
	Node* tail = fifth;
	cout<<"PRINTING LL : "<<endl;
	printLinkedList(head);
	
	
	
	//PRINTING LENGTZH OF LINKEDLIST
	cout<<endl<<"Length of Linked List is :"<<endl;
	int length=getLength(head);
	cout<<length<<endl;
	
	
	//INSERTING A NODE IN LINKED LIST
	
	//head ke piche 
	//tail ke badme
	//bich me
	
	
	//INSERTION AT HEAD
	
	// insertAtHead(head,tail,500);
	// //pass by refernce krna hai humesha
	// cout<<"PRINTING LL : "<<endl;
	// printLinkedList(head);
	
	
	//insert at TAIL
	
	// insertAtTail(head,tail,500);
	// //pass by refernce krna hai humesha
	// cout<<"PRINTING LL : "<<endl;
	// printLinkedList(head);
	
	//insert at a POSITION
	
	// insertAtPosition(head,tail,55,6);
	// //pass by refernce krna hai humesha
	// cout<<"PRINTING LL : "<<endl;
	// printLinkedList(head);
	
	
	
	
	
	
	
	
	
	//------------------------------------------------------------------------
	
	
	deleteNode(head,tail,5);
	printLinkedList(head);
	cout<<endl;
	
	
	
	
	return 0;
}