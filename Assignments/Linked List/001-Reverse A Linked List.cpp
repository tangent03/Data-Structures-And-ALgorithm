/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 */
 
 
 // LEETCODE QUESTION
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

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
        
    }
};



//REVERSE A SINGLY LINKED LIST