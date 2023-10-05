class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack <int> st;
        int leftsmall[n];
        int rightsmall[n];

        //finding the Left next smallest element/index in the height..
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                // not get the smallest element index and we reach up to the boundary..
                leftsmall[i] = 0;
            }
            else{
                leftsmall[i] = st.top() + 1;
            }
            st.push(i);
        }
        // poping the element in the stack so resused for right half..
        while(!st.empty()){
            st.pop();
        }
         //finding the Right next smallest element/index in the height..
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                // not get the smallest element index and we reach up to the boundary..
                rightsmall[i] = n-1;
            }
            else{
                rightsmall[i] = st.top() - 1;
            }
            st.push(i);
        }

        // finding the maximum area now..
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxi;

    }
};
