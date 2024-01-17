#include<bits/stdc++.h>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> mp;

        for(auto it : arr){
            mp[it]++;
        }

        unordered_set <int> occurence;

        for(auto it : mp){
            int element = it.second;

            if(occurence.find(element) != occurence.end()){
                return false;
            }

            occurence.insert(element);
        }
        return true;
    }
};

