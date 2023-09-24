#include <bits/stdc++.h> 
#include <stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack <char> st;
    int n = s.length();
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
            st.push(ch);
        }
        else{
            // get any close bracket  or any letter
            if(ch == ')'){ // get the close bracket now to check whether it is redundant or not.
                bool isredundant = true;
                while (st.top() != '(') {
                  char top = st.top(); // getting the top character in the stack.
                  if(top == '+' || top == '-' || top == '*' || top == '/' || top == '%' ){
                    isredundant = false;
                  }
                  st.pop();
                }
                // checking it is redundant or not
                if(isredundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
