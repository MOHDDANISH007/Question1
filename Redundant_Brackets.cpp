#include <bits/stdc++.h> 
#include <stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack <char> st;
    int n = s.length();
    for(int i=0; i<n; i++){
        char ch = s[i];
        // checking the conditions for open bracket or any operator if it is yes then please put or insert in the stack and go ahead.
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
                st.pop(); // if it is not redundant then make sure to pop the open bracket to check the another one is redundant bracket or not and go ahead.
            }
        }
    }
    return false;
}

