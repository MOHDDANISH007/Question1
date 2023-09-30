double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	if(a.size() > b.size()){
		return median(b, a);
	}

	int m = a.size();
	int n = b.size();

	int low = 0;
	int high = m;

	while(low <= high){
		int px = low + (high - low) / 2;
		int py = (m + n + 1) / 2 - px;
        
		// This for left half..
		int x1 = (px == 0) ? INT_MIN: a[px - 1];
		// Taking no element from the a -> array.

		int x2 = (py == 0) ? INT_MIN: b[py - 1];
		// Taking no element from the b -> array.

		// This for right half

		int x3 = (px == m) ? INT_MAX: a[px];
		// Taking all the element from the a -> array.

		int x4 = (py == n) ? INT_MAX: b[py];
		// Taking all the element from the b -> array.

		if(x1 <= x4 && x2 <= x3){
			if( (m + n) % 2 == 1){
				return max(x1,x2);
			}
			else{
				return (max(x1, x2) + min(x3, x4)) / 2.0;
			}
		}
		else if(x1 > x4){
			high = px - 1;
