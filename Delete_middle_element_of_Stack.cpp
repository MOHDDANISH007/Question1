class Solution
{
    public:
    void solve(stack<int>&s, int k){
        if(s.size() == 0){
            return;
        }
        if(k == 1){
            s.pop();
        }
        int val = s.top();
        s.pop();
        solve(s, k-1);
        s.push(val);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        int k;
        if(sizeOfStack/2 == 0){
            k = sizeOfStack/2; 
        }
        else{
             k = sizeOfStack/2+1;
        }
        
        solve(s, k);
         
    }
};
