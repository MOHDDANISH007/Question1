class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k){
            return "0";
        }
        if(k <= 0){
            return num;
        }

        stack <char> st;
        st.push(num[0]);
        string ans = "";

        for(int i=1; i<num.length(); i++){
            while(k > 0 && !st.empty() && num[i] < st.top() ){
                k--;
                st.pop();
            }

            if(st.empty() && num[i] == '0'){
                continue;
            }
            st.push(num[i]);
        }

        while(k > 0 && !st.empty()){
            k--;
            st.pop();
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        if(ans.length() > 0){
            return ans;
        }
        return "0";

    }
};
