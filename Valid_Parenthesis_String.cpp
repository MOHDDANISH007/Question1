#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> extra_bracket;
        stack<int> asterisk;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') {
                extra_bracket.push(i);
            } else if(s[i] == '*') {
                asterisk.push(i);
            } else if(s[i] == ')') {
                if(!extra_bracket.empty()) {
                    extra_bracket.pop(); // Pop corresponding '('
                } else if(!asterisk.empty()) {
                    asterisk.pop(); // Pop '*' as it can act as '('
                } else {
                    return false; // ')' found without a corresponding '(' or '*'
                }
            }
        }

        while(!extra_bracket.empty()) {
            if(asterisk.empty()) {
                return false; // If no '*' left to balance the '('
            } else if(extra_bracket.top() < asterisk.top()) {
                extra_bracket.pop(); // Pop '('
                asterisk.pop(); // Pop '*'
            } else {
                return false; // '*' is before '(' which cannot be balanced
            }
        }

        return extra_bracket.empty(); // Check if all '(' are balanced
    }
};
