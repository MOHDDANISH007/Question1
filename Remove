class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size() - 1;
        int AliceScore = 0; //  Counting the score of alice 
        int BOBScore = 0; // counting the score of bob
        for(int i=1; i<n; i++){
            char prev = colors[i-1]; // Geting The character of the string according to the i th index  (Back value )
            char next = colors[i+1]; // Geting The character of the string according to the i th index  (Forward value).
            if(colors[i] == 'A' && prev == 'A' &&  next == 'A'){// checking the condition it's correct or not if is then go ahead.
                AliceScore++; 
            }
            else if(colors[i] == 'B' && prev == 'B' && next == 'B'){//// checking the condition it's correct or not if is then go ahead.
                BOBScore++;
            }
        }
        if(AliceScore > BOBScore){
            return true;
        }
        else{
            return false;
        }
    }
};
