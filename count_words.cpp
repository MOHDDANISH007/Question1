#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

int countWords(string input) {
    int words = 1;
    if(input.size() == 0){
        return 0;
    }
    else{
        for(int i=0; i<input.size(); i++){
            if(input[i] == ' '){
                words++;
            }
        }
    }
    return words;
}

int main() {
    string input;
    getline(cin, input);
    int output = countWords(input);
    cout << output << endl;
    return 0;
}
