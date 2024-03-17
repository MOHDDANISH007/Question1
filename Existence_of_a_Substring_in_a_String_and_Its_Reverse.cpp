#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        string reverse_string = s;
        reverse(reverse_string.begin(), reverse_string.end());

        int n = s.size();

        for (int i = 0; i < n - 1; i++) {
            string substr = s.substr(i, 2);
            // reverse_string.find(substr) != reverse_string.end()
            
            if (reverse_string.find(substr) != string::npos) {
                return true;
            }
        }
        return false;
    }
};
