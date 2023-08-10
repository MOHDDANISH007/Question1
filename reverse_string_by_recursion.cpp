#include<iostream>
using namespace std;
void reverse(string& str, int i ,int j){
    cout << str <<endl;
    if(i > j){
        return;
    }
    swap(str[i] , str[j]);
    i++;
    j--;
    return reverse(str, i, j);
}


int main(){
    string str ="Danish";
    cout << str <<" ";
    cout <<endl;
    cout <<  str.length()-1 <<endl;
    reverse(str, 0 , str.length()-1);
    cout <<  str << endl;
}
