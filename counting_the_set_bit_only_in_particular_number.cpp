#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
int main(){
    int number;
    cout << "Enter The number of set bit=" << endl;
    cin >> number;

    int cnt = 0;
    while(number != 0){
        number  = number & (number-1);
        cnt ++;
    }
    cout << "The set bit's are = " << cnt << endl;
    
}
