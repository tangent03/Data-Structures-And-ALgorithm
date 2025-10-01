         // BINARY SEARCH TREEEE
         
#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int value){
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
	
};

Node* insertIntoBST(Node* root, int data){
	if(root == NULL){
		root = new Node(data);
		return root;
	}
	
	//its not the first node
	if(data > root->data){
		root->right = insertIntoBST(root->right,data);
	}
	else{
		root->left = insertIntoBST(root->left,data);
	}
}


void createBST(Node* &root){
	cout<<"Enter the Data :  "<<endl;
	int data;
	cin>>data;
	while(data!= -1){
		root = insertIntoBST(data)
		cin>>data;
	}
}

void levelOrderTraversal(Node* root){
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		
		if(temp == NULL){
			
		}
		else{
			
		}
	}
}



int main(){
	
	Node* root = createBST();
	
	return 0;
}