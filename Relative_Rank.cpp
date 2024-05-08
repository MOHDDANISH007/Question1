#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //  Naive Solution
        // vector<int> sorted_score = score;

        // sort(sorted_score.begin(), sorted_score.end(), greater<int>());
        // vector<string> medal={"Gold Medal", "Silver Medal", "Bronze Medal"};
        // unordered_map<int,string> mp;

        // for(int i=0; i<sorted_score.size(); i++){
        //     if(i==0){
        //         mp[sorted_score[i]] = medal[i];
        //     }
        //     else if(i==1){
        //         mp[sorted_score[i]] = medal[i];
        //     }
        //     else if(i==2){
        //         mp[sorted_score[i]] = medal[i];
        //     }else{
        //         mp[sorted_score[i]] = to_string(i+1);
        //     }
        // }

        // vector<string> result;

        // for(auto it:score){
        //     result.push_back(mp[it]);
        // }
        // return result;

        // 2nd Approach


        // Priority queue to store pairs of (score, index)
        priority_queue<pair<int, int>> heap;

        // Insert all scores with their respective indices into the heap
        for (int i = 0; i < score.size(); i++) {
            heap.push({score[i], i});
        }

        // 2nd Approach
        
        // Result vector to store ranks
        vector<string> result(score.size());

        int rank = 0;
        while (!heap.empty()) {
            // Get the index of the athlete with the highest score
            int index = heap.top().second;
            heap.pop(); // Remove the top element from the heap

            // Assign rank based on position
            if (rank == 0) {
                result[index] = "Gold Medal";
            } else if (rank == 1) {
                result[index] = "Silver Medal";
            } else if (rank == 2) {
                result[index] = "Bronze Medal";
            } else {
                result[index] = to_string(rank + 1); // Convert rank to string
            }

            rank++; // Increment the rank
        }

        return result;
    }
};
