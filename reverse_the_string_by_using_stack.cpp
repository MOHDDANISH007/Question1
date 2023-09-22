#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str = "danish";
    stack <char> s;
    int n = str.length();
    for(int i=0; i<n; i++){
        char ch = str[i];
        s.push(ch);
    }
    string ans = "";
    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout << "The reverse string is " << ans << endl;
}
