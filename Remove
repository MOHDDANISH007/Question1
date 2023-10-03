class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size() - 1;
        int AliceScore = 0;
        int BOBScore = 0;
        for(int i=1; i<n; i++){
            char prev = colors[i-1];
            char next = colors[i+1];
            if(colors[i] == 'A' && prev == 'A' &&  next == 'A'){
                AliceScore++; 
            }
            else if(colors[i] == 'B' && prev == 'B' && next == 'B'){
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
