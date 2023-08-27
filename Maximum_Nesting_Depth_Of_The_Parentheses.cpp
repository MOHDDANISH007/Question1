int maxDepth(string s) {
	int ans = 0;
	int maxi = INT_MIN;
	int n = s.size();
	
	for(int i=0; i<n; i++){
		if(s[i] == '('){
			ans++;
			maxi = max(ans,maxi);
		}
		else if(s[i] == ')'){
			ans--;
		}
	}
	return maxi;
}
