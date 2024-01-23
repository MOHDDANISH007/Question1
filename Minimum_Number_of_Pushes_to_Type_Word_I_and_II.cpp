class Solution {
public:
   int minimumPushes(string word) {
        vector<int> ans(26, 0);

        for (auto it : word) {
            ans[it - 'a']++;
        }
        sort(ans.rbegin(), ans.rend());

        int minimum_time = 0;

        for (int i = 0; i < 26; i++) {
            int freq = ans[i];
            int position = (i / 8) + 1;
            minimum_time += (freq * position); 
        }
        return minimum_time;
    }
















    //     unordered_map<int,int> mp;
    //     int assign_key = 2;
    //      int minimum_time = 0;

    //     for(auto it:word){
    //         if(assign_key > 9){
    //             assign_key = 2;
    //         }
    //         mp[assign_key]++;
    //         minimum_time += mp[assign_key];
    //         assign_key++;
    //     }
       
    
    //     return minimum_time;
    // }
};
