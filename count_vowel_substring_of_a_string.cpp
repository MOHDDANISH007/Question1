class Solution {
public:
    bool NotVowel(char character){
        if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'){
            return true;
        }else{
            return false;
        }
    }

    int countVowelSubstrings(string word) {
        int result = 0;
        for(int i=0; i<word.size(); i++){
            unordered_set<char> set;
            for(int j=i; j<word.size(); j++){
                if(NotVowel(word[j]) == false){
                    break;
                }
                set.insert(word[j]);
                if(set.size() == 5){
                    result++;
                }
            }
        }
        return result;
    }
};
