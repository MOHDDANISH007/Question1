class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;

        for(auto it:s){
            if(it == c){
                ans++;
            }
        }

        return (ans * (ans + 1)/2);
        
        // for(int i=0; i<s.size(); i++){
        //     if(s[i] == c){
        //         for(int j=i; j<s.size(); j++){
        //             if(s[j] == c){
        //                 ans++;
        //             }
        //         }
        //     }
        // }
        // return ans;
    }
};
