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
	
	int seachInOrder(int inOrder[], int size, int target){
		for(int i=0;i<size;i++){
			if(inOrder[i] == target){
				return i;
			}
		}
		return -1;
	}

	Node* constructTreeFromPreAndInorderTraversal(int preOrder[],
	int inOrder[],int preIndex,int inOrderStart,
	int inOrderEnd,int size){
	//base case
	if(preIndex>=size || inOrderStart > inOrderEnd){
		return NULL;
		}
		//1 case main solve krta hu
		int element = preOrder[preIndex];
		preIndex++;
		Node* root = new Node(element);
		//element search krna padega inorder me
		int position = searchInOrder(inOrder,size,element);
		
		//baaki recursion sambhal lega
		
		root->left = constructTreeFromPreAndInorderTraversal(preOrder,inOrder,preIndex,
		inOrderStart,position-1,size);
		root->right = constructTreeFromPreAndInorderTraversal(preOrder,inOrder,preIndex,
		inOrderEnd,position+1,size);
		
		return root;
		
	}

int main(){
	int inOrder[] = {10,8,6,2,4,12};
	int preOrder[] = {2,8,10,6,4,12};
	int size = 6;
	int preOrderIndex=0;
	int inOrderStart=0;
	int inOrderEnd= 5;
	
	Node* root = constructTreeFromPreAndInorderTraversal(preOrder,inOrder,preOrderIndex,
		inOrderEnd,size);
		
		cout<<"Printing the entire tree"<<endl;
		levelOrderTraversal(root);
	return 0;
}