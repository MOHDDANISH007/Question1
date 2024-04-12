class Solution {
public:
       void NGE(vector<int>& nums, vector<int>& next_greatest_element) {
        int n = nums.size();
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums[i]) { // 1
                st.pop();
            }
            if (!st.empty()) {
                next_greatest_element[i] = st.top();
            }
            if (st.empty() || nums[i] > st.top()) { // don't understand this condition nums[i] > st.top() again when in line 12 
                st.push(nums[i]);
            }
        }
    }

    void PGE(vector<int>& nums, vector<int>&previous_greatest_element) {
        int n = nums.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() < nums[i]) { // 24
                st.pop();
            }
            if (!st.empty()) {
                previous_greatest_element[i] = st.top();
            }
            if (st.empty() || nums[i] > st.top()) { // don't understand this condition nums[i] > st.top() again when in line 24 
                st.push(nums[i]);
            }
            
        }
    }



    int trap(vector<int>& height) {
        vector<int> previous_greatest_element(height.size(), -1);
        vector<int> next_greatest_element(height.size(), -1);

        NGE(height,next_greatest_element);
        PGE(height, previous_greatest_element);

        int ans = 0;
        for(int i=0; i<height.size(); i++){
            int trappedWater = min(next_greatest_element[i], previous_greatest_element[i]) - height[i];
            if(trappedWater > 0){
                ans += trappedWater;
            }
        }
        if(ans != 0){
            return ans;
        }else{
            return 0;
        }
    }
};
