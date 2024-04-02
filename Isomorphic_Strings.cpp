class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i = 0; i < s.size(); i++){
            char element1 = s[i];
            char element2 = t[i];

            if((mp1.find(element1) != mp1.end() && mp1[element1] != element2) || (mp2.find(element2) != mp2.end() && mp2[element2] != element1)){
                return false;
            }
           


            mp1[element1] = element2;
            mp2[element2] = element1;
        }
        return true;
    }
};
