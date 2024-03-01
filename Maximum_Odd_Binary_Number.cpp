class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<string> ans(s.size(), "0");

        int size = s.size();
        int j = 0 ;

        for(int i=0; i<size; i++){
            if(s[i] == '1'){
                ans[j++] = s[i];
            }
        }

        // swaping last position of 1(means where my j is stand) in answer with last element of answer
        swap(ans[j-1] , ans[ans.size()-1]);
        string sol = "";
        for(int i=0; i<size; i++){
            sol += ans[i];
        }

        return sol;
    }
};
