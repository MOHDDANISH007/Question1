#include <iostream>
#include <vector>
#include <climits>  // Include this header for INT_MIN

// This question based on two pointer approach

using namespace std;

class Solution {
public:
    // int maxi_element(vector<int>& tokens) {
    //     int maxi = INT_MIN;
    //     for (auto it : tokens) {
    //         maxi = max(it, maxi);
    //     }
    //     return maxi;
    // }

    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int maxiScore = 0;
        int score = 0;
        int i=0;
        int j = tokens.size()-1;

        while(i<=j){
            if(tokens[i] <= power){
                score = score + 1;
                power = power - tokens[i];
                maxiScore = max(score ,maxiScore);
                i++;
            }
            else if(score > 0){
                power = power + tokens[j];
                score = score - 1;
                j--;
            }
            else{
                break;
            }
        }

        return maxiScore;






        // 76 case is not running properly => [91,4,75,70,66,71,91,64,37,54] power = 20
        // int maxi = maxi_element(tokens);

        // int score = 0;

        // int i = 0;
        // int n = tokens.size();

        // while (i < n) {
        //     if (tokens[i] <= power) {
        //         score += 1;
        //         power -= tokens[i];
        //         i++;
        //     } else if (score > 0) {
        //         power += maxi;
        //         score -= 1;
        //     } else {
        //         break;
        //     }
        // }
        // return score;
    }
};
