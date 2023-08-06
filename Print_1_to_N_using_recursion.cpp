#include <iostream>
#include <vector>

using namespace std;

void N(int n, vector<int>& ans) {
    if (n == 0) {
        //ans.push_back();
        return;
    }
    N(n - 1, ans);
    ans.push_back(n);
    return ;
    
}

vector<int> printNos(int x) {
    vector<int> ans;
    N(x, ans);
    return ans;
}

