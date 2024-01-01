class Solution{
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_set <int> remainder_count;
        
        if(nums.size() % 2 != 0){
            return false;
        }
        
        for(int i=0; i<nums.size(); i++){
            int r1 = nums[i] % k;
            int r2 = k - r1;
            
            if(remainder_count.find(r2) != remainder_count.end()){
                remainder_count.erase(r2);
            }
            else if(r1 == 0 && remainder_count.find(r1) != remainder_count.end()) {
                remainder_count.erase(r1);
            }
            else{
                remainder_count.insert(r1);
            }
        }
        int n = remainder_count.size();
        if(n == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    
/*
vector<bool> used_element(nums.size(), false);

for (int i = 0; i < nums.size(); i++) {
    bool isPair = false;
    if (used_element[i] == true) {
        continue;
    }

    for (int j = i + 1; j < nums.size(); j++) {
        if (used_element[j] == true) {
            continue;
        }

        if ((nums[i] + nums[j]) % k == 0) {
            used_element[i] = true;
            used_element[j] = true;
            isPair = true;
            break; // Exit the inner loop once a pair is found
        }
    }

    if (isPair == false) {
        return false;
    }
}

for (int i = 0; i < used_element.size(); i++) {
    if (used_element[i] == false) {
        return false;
    }
}

return true;

*/
};
