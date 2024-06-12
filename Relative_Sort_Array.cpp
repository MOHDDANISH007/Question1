class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        //Brute Force Approach.....

        // vector<int> result;
        // for(int i=0; i<arr2.size(); i++){
        //     for(int j=0; j<arr1.size(); j++){
        //         if(arr1[j] == arr2[i]){
        //             result.push_back(arr1[j]);
        //             arr1[j] = -1;
        //         }
        //     }
        // }

        // sort(arr1.begin(), arr1.end());
        // for(int i=0; i<arr1.size(); i++){
        //     if(arr1[i] != -1){
        //         result.push_back(arr1[i]);
        //     }
        // }


        // Optimal Approach...
        vector<int> result;


        map<int,int> mp;
            for (auto it : arr1) {
            mp[it]++;
        }

        for (int i = 0; i < arr2.size(); i++) {
            int nums = arr2[i];
            if (mp.find(nums) != mp.end()) {
                while (mp[nums] > 0) {
                    result.push_back(nums);
                    mp[nums]--;
                }
                if (mp[nums] == 0) {
                    mp.erase(nums);
                }
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            while (it->second > 0) {
                result.push_back(it->first);
                it->second--;
            }
        }

        return result;
        }
};
