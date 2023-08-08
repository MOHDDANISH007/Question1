int searchInsert(vector<int>& arr, int m)
{
	int s = 0;
	int e = arr.size()-1;
	int ans = arr.size();
	int mid = s + (e-s)/2;
	while(s <= e){
		if(arr[mid] >= m){
			ans = mid;
			e = mid - 1;   
		}
		else{
			s = mid +1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
}
