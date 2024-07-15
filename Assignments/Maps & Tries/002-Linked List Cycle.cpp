/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
	public:
	// bool hasCycle(ListNode* head){
	// 	map<ListNode* , bool> table;
	// 	ListNode* temp = head;
	// 	while(temp!=NULL){
	// 		if(table[temp]==false){
	// 			table[temp]=true;
	// 		}
	// 		else{
	// 			//cycle present hai
	// 			return true;
	// 		}
	// 		temp=temp->next;
	// 	}
	// 	//loop not present
	// 	return false;
	// }











    // bool hasCycle(ListNode* &head){
		// ListNode* slow = head;
		// ListNode* fast = head;
		// while(fast!=NULL){
			// fast = fast->next;
			// if(fast!=NULL){
				// fast=fast->next;
				// slow=slow->next;
			// }
// 			
			// //check for loop
			// if(fast==slow){
				// return true;
			// }
		// }
		// return false;
	// }
	
	
	
	
	
	
		bool hasCycle(ListNode* head){
			unordered_map<Node*,bool> mapping;
			ListNode* temp = head;
			
			while(temp!=NULL){
				//address check
				if(mapping.find(temp) != mapping.end()){
					//cycle present
					return true;
				}
				else{
					//node not visited beforehand
					//srore
					mapping[temp]= true;
				}
				temp = temp->next;
				
				//address store
			}
			//cycle absent
			return false;
	}
};