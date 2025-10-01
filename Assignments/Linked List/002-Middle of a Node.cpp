//SLOW AND FAST APPROCH ALGORITHM;

//1st way TC- O(N);
//but 2 passes - 1 for length 2nd for traversing

//2nd way slow and fast approach or tortorise approach
//fast will go 2 steps and then slow will go 1 step.

class Solution{
	public:
	
//1st approach


	// int getLength(ListNode* head){
		// int length=0;
		// ListNode* temp = head;
		// while(temp!=NULL){
			// length++;
			// temp=temp->next;
		// }
		// return length;
	// }
// 	
	// ListNode* middleNode(ListNode* head){
		// int n = getLength(head);
		// int position = n/2+1;
// 		
		// ListNode* temp = head;
		// while(position != 1){
			// position--;
			// temp=temp->next;
		// }
		// return temp;
	// }
// 	


//----------------------------------------------










//2nd Way - SLOW AND FAST APPROACH

ListNode* slow = head;
ListNode* fast = head;

while(fast!=NULL && fast->next !=NULL){  
	fast = fast->next;
	if(fast!=NULL){
		fast = fast->next;
		slow=slow->next;
	}
}
return slow;

//condition agar fast->next != NULL krde to isse phele wala mid aajaegaaa
	
	
}