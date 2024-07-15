
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// 
// There is a cycle in a linked list if there is some node in
 //the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// 
// Return true if there is a cycle in the linked list. Other
//wise, return false.
// 
//  
// 
// Example 1:
// 
// 
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the 
//tail connects to the 1st node (0-indexed).
// Example 2:
// 
// 
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list,
// where the tail connects to the 0th node.
// Example 3:
// 
// 
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
//  
// 
// Constraints:
// 
// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.
//  
// 
// Follow up: Can you solve it using O(1) (i.e. constant) memory?
// 
//FIRST APPROACH - MAPS - TC- O(N);
//SECOND APPROACH - SLOW AND FAST
// 


// fast 2 kadam slow 1 kadam... ek time pe agar fast == slow hogya to loo[ present hai
// fir starting point of loop ke lie slow ko head pe rakho aur fast and slow ko 1 1 kadam
//aage badhao. jahan meet hue wahan starting point hai


//remove loop ke lie starting point nikalo fir uske phele wale ko remove krdo (loop me loop
// lagaaenge jab tk node ke next starting point na ho )

class Solution{
	public:
	
// SLOW FAST METHOD - 	
	bool checkLoop(ListNode* &head){
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast!=NULL){
			fast = fast->next;
			if(fast!=NULL){
				fast=fast->next;
				slow=slow->next;
			}
			
			//check for loop
			if(fast==slow){
				return true;
			}
		}
		return false;
	}
	
	//starting point of loop
	
	
	
	
	
	
	Node* getStartingPoint(Node* head){
		//check for Loop
		Node* slow = head;
		Node* fast = head;
		while(fast!=NULL){
			fast= fast->next;
			if(fast!=NULL){
				fast=fast->next;
				slow=slow->next;
			}
			if(fast==slow){
				break;
			}
		}
		if(fast==NULL){
			return NULL;
		}
		//yahan pohche mtlab slow and fast meet kr chuke hai
		slow =  head;
		while(fast!=slow){
			slow=slow->next;
			fast= fast->next;
		}
		return slow;
	}
	
	//remove loop
	
	void removeLoop(Node* &head){
		//check loop
		
		Node* slow = head;
		Node* fast = head;
		
		while(fast!=NULL){
			fast=fast->next;
			if(fast !=NULL){
				fast = fast->next;
				slow = slow->next;
			}
			if(fast==slow){
				break;
			}
		}
		
		//yahan pphcha matlab slow and fast meet kr chuke hai
	
		slow=head;
		
		while(fast !=slow){
			slow=slow->next;
			fast=fast->next;
		}
		
		Node* startPoint = slow;
		
		Node* temp = slow;
		while(temp->next !=startPoint){
			temp=temp->next;
		}
		temp->next=NULL;
		
}
	
//MAP MATHOD	
	bool hasCycle(ListNode* head){
		map<ListNode* , bool> table;
		ListNode* temp = head;
		while(temp!=NULL){
			if(table[temp]==false){
				table[temp]=true;
			}
			else{
				//cycle present hai
				return true;
			}
			temp=temp->next;
		}
		//loop not present
		return false;
	}
}





//FOLLOW UP QUESTIONS FOR LOOP CHECK;

//1, Check for loop
//2. Starting Point of Loop
//3. remove Loop
