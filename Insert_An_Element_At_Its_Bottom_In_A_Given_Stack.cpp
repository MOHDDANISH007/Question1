#include <bits/stdc++.h> 
#include <stack>
void solve(stack<int>& myStack, int x){
    if(myStack.empty() == true){
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();
    solve(myStack, x); // Recursive call here
    myStack.push(num);
    return;
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack, x);
    return myStack;
}
