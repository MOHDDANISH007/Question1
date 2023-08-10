#include <iostream>
using namespace std;

bool checkingpalindrome(string str ,int i, int j){
    cout << str <<endl;
    if(i > j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }
    else{
        return checkingpalindrome(str, i+1, j-1);
    }
}

int main(){
    string str = "abba";
    bool ispalindrome = checkingpalindrome(str, 0, str.length()-1);
    if(ispalindrome) {
        cout <<"Palindrome string" <<endl;
    }
    else{
        cout << "Not Palindrome String" <<endl;
    }
    return 0;
}
