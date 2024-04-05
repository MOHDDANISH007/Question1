#include <string>
#include <cmath>
#include <stack> // Include stack header for stack container
#include <algorithm> // Include algorithm header for reverse function

using namespace std; // Add this line to avoid qualification of standard library types

class Solution {
public:
    string makeGood(string s) {

        // Brute Force Approach
        
        // if(s.length() == 0){
        //     return s;
        // }
        
        // int n = s.length(); // Store the length of the string
        
        // for(int i = 0; i < n - 1; i++){ // Loop through the string
        //     char ch1 = s[i];
        //     char ch2 = s[i+1];
        //     if(abs(ch1 - ch2) == 32){ // Check if characters are same but different cases
        //         s.erase(i, 2); // Erase characters at index i and i+1
        //         i -= 2; // Move back the index to recheck the modified string
        //         n -= 2; // Update the length of the string after erasing characters
        //         if (i < 0) // Ensure index doesn't become negative
        //         cout  << i << endl;
        //             i = -1;
        //     }
        // }

        // Optimal Approach


        if(s.length() == 0){ 
            return s; 
        }

        stack<char> st; 
        int n = s.length();
        for(int i=0; i<n; i++){
            char ch1 = s[i];
            if(!st.empty()){ 
                char ch2 = st.top();
                if(abs(ch1 - ch2) == 32){
                    st.pop();
                }
                else{
                    st.push(ch1);
                }
            } else {
                st.push(ch1); // push ch1 if stack is empty
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top()); 
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
