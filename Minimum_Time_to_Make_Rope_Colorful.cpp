class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int min_time = 0;
        int prev_ballon = 0;

        for(int i=1; i<colors.size(); i++){
            if(colors[prev_ballon] != colors[i]){
                cout << i << endl;
                prev_ballon = i;
            }
            else{
                if(neededTime[prev_ballon] < neededTime[i]){
                    min_time += neededTime[prev_ballon];
                    prev_ballon = i;
                }
                else{
                    min_time += neededTime[i];
                }
            }
        }
        return min_time;
    }
};
