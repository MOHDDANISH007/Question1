
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void rec(int n, vector<string>& ans) {
    if (n == 0) {
        return;
    }
    ans.push_back("Coding Ninjas");
    rec(n - 1, ans);
}

vector<string> printNTimes(int n) {
    vector<string> ans;
    rec(n, ans);
    return ans;
}


