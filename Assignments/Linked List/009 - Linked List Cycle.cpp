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

    bool hasCycle(ListNode* &head){
        
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(slow !=fast){
            return false;
        }
        else{
            return true;
        }

    
    
    }
};