								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
// BRUTE FORCE - SORT THE ARRAY AND PRINT THE KTH SMALLEST/LARGEST ELEMENT -
// T(C)=O(NLOGN).

//OPTIMAL SOLUTION - USE MAX HEAP AND MIN HEAP.
//IN THIS WE MAKE A PRIORITY QUEUE OF MAXHEAP AND THAN WE PUSH THE K ELEMNTS 
//OF ARRAY IN PRIORITY QUEUE AND IF SIZE OF MAXHEAP > K THAN WE POP THE LARGEST 
//ELEMNT.
//SO AFTER THIS WE PRINT THE TOP ELEMNT OF PRIORITY QUEUE - KTH SMALLES ELEMENT

//IF WE SE KTH SMALLEST, FARTHEST, LARGEST, LONGEST, ESA KUCH TO HEAPS SOCHNA

//IF WE SEE KTH SMALLEST ,MINIMUM THEN WE USE MAX_HEAP.
//IF WE SEE KTH LARGEST, MAXIMUM THEN WE USE MIN_HEAP.

//ULTA

//TIME COMPLEXITY - O(NLOG K)




//SO BASICALLY MAX_HEAP - POPS THE MAXIMUM NUMBER 
//IN SMALLES KTH ELEMENT WE PUT K ELEMENTS IN MAX HEAP AND THEN IF SIZE OF
//MAX-HEAP IS GREATER THAN K THEN WE POPS THE TOP ELEMENT THAT IS MAXIUMUM NUMBER.
//AND AT THE END WE GET THE TOP ELEMENT AS THE KTH SMALLES ELEMENT

//HEAP ULTE HOTE HAI STACK IS(MENE JAISA DEKHA HAI ABHI UTUBE PE)


// 
// Explanation:
// 1.Min-heap Creation: The priority_queue<int, vector<int>, greater<int>> minHeap;
// creates a min-heap, where the smallest element is always at the top.
// 2.Push Elements: We push elements from the array into the min-heap.
// 3.Control Heap Size: If the size of the min-heap exceeds 𝑘
// 4. we pop the smallest element, ensuring the heap size remains 𝑘.
// Result: After processing all elements, the top of the min-heap is the 
// 𝑘
// kth largest element in the array.
// This approach ensures that the algorithm runs in 
// 𝑂(𝑛log𝑘)
// O(nlogk) time complexity, which is efficient for this problem.




#include <bits/stdc++.h>
using namespace std;


int smallestKthElement(int arr[], int start, int end, int k){
	
	priority_queue<int>maxHeap;
	for(int i=start;i<=end;i++){
		maxHeap.push(arr[i]);
		if(maxHeap.size()>k){
			maxHeap.pop();
		}
	}
	return maxHeap.top();
}

int largestKthElement(int arr[],int start,int end, int k){
	
	priority_queue<int, vector<int>, greater<int>>minHeap; //creates minHeap.
	for(int i=start;i<=end;i++){
		minHeap.push(arr[i]);
		if(minHeap.size()>k){
			minHeap.pop();
		}
		
	}
	return minHeap.top();
}


int main(){
	
   int n;
   cin>>n;
   int arr[n];
   int start=0;
   int end=n-1;
   for(int i=start;i<=end;i++){
   	cin>>arr[i];
   }
   int k;
   cin>>k;
   int SmallestKthAns = smallestKthElement(arr,start,end,k);
   cout<<"Smallest kth element in array is : "<<SmallestKthAns<<endl;
   int LargestKthAns = largestKthElement(arr,start,end,k);
   cout<<"Largest kth element in array is : "<<LargestKthAns<<endl;
    
    
}

















