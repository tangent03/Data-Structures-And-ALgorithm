int findAllSubarraysWithGivenSum(vector<int> &arr, int k ){
	unordered_map<int,int> mpp;
	mpp[0] = 1;
	int count = 0;
	int preSum =0;
	for(int i=0;i<arr.size();i++){
		preSum = preSum + arr[i];
		int remove = preSum - k;
		count = count + mpp[remove];
		mpp[preSum] += 1;
	}
	return count;
}