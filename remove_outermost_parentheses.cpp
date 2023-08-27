class Solution {
public:
    string removeOuterParentheses(string s) {
        string a = "";
        int balanced = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                if(balanced > 0){
                    a += s[i];
                }
                balanced++;
            }
            else if(s[i] == ')'){
                balanced--;
                if(balanced > 0){
                    a += s[i];
                }
            }
        }
        return a;
    }
};
