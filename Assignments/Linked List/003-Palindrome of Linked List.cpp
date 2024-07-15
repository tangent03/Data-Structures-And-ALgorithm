class Solution {
	public:
	
	
	ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
		//base case
		if(curr==NULL){
			return prev;
		}
		
		//1 case hum solve krenge
		ListNode* nextNode = curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextNode;
		
		//Bakki recursion sabhalega
		ListNode* recursionAns = reverseUsingRecursion(prev,curr);
		return recursionAns;
	}
	
	
	ListNode* middleNode(ListNode* head){
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast->next!=NULL){
                fast = fast->next;
                if(fast->next!=NULL){
                    fast = fast->next;
                    slow=slow->next;
                }
            }
            return slow;




	}
	
	bool comparelist(ListNode* head1, ListNode* head2){
		while(head1 !=NULL && head2!=NULL){
			if(head1->val != head2->val){
				return false;
			}
			else{
				head1=head1->next;
				head2=head2->next;
			}
		}
		return true;
	}
	
	bool isPalindrome(ListNode* head){
		
		//1st approch TC-O(n)
		//first make a LinkedList 
		//Reeverse that LinkedList
		//Compare the origianl and reversed LL
		
		
		
		
		
		
		
		
		
		
	//2nd approach - in this the space is constant but it is a bad practice
	//as we are disturbing the given data;
		// TC-O(N)
		 
		 
		 
		//break the LL in 2 halves
		ListNode* middleNode = middleNode(head);
		ListNode* head2 = middle->next;
		middleNode->next =NULL;
		//reverse the 2nd Linked List
		
		ListNode* prev = NULL;
		ListNode* curr= head2;
		head2=reverseUsingRecursion(prev,curr);
		//Compare Both Linked List
		bool ans = compareList(head,head2);
		return ans;
		
	}
}