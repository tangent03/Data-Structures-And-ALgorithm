#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		this->data = val;
		this->left = NULL;
		this->right=NULL;
	}
	
	
};

//it returns root node of created tree
	Node* createTree(){
		cout<<"Enter The value For Node: "<<endl;
		int data;
		cin>>data;
		
		if(data==-1){
			return NULL;
		}
		
		//Step1 : Create Node
		Node* root = new Node(data);
		//Step 2: Create Left subtree
		cout<<"Left of Node : "<<root->data <<endl;
		root->left = createTree();
		//Step 3: Create right subtree
		cout<<"Right of Node : "<<root->data <<endl;
		root->right = createTree();
		return root;
	}
	
	void preOrderTraversal(Node* root){
		//base case
		if(root==NULL){
			return;
		}
		
		//N L R
		//N
		cout<<root->data<<" ";
		//L
		preOrderTraversal(root->left);
		//R
		preOrderTraversal(root->right);
	}
	
	void inOrderTraversal(Node* root){
		//base case
		if(root==NULL){
			return;
		}
		//LNR
		//L
		inOrderTraversal(root->left);
		//N
		cout<<root->data<<" ";
		//R
		inOrderTraversal(root->right);
		
	}
	
	void postOrderTraversal(Node* root){
		//base case
		if(root==NULL){
			return;
		}
		
		//LRN
		//L
		postOrderTraversal(root->left);
		//R
		postOrderTraversal(root->right);
		//N
		cout<<root->data<<" ";	
	}
	
	void levelOrderTraversal(Node* root){
		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		
		//asli traversal start krtr hai
		
		while(q.size()>1){
			Node* front = q.front();
			q.pop();
			
			if(front == NULL){
				cout<<endl;
				q.push(NULL);
			}
			else{
				//valid node wala case
				cout<<front->data<<" ";
			
				if(front->left !=NULL){
					q.push(front->left);
				}
				if(front->right != NULL){
					q.push(front->right);
				}
			}
			
			
		}
	}

int main(){
	
	Node* root = createTree();
	cout<<root->data<<endl;
	
	return 0;
}


//3 main traversal in trees
//1. PreOrder - NLR
//2. InOrder - LNR
//3. PostOrder - LRN