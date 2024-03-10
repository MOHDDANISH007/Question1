#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // optimal solution
        set<int> s;
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                s.insert(nums1[i]);
                i++; 
                j++; 
            } else if (nums1[i] < nums2[j]) {
                i++; 
            } else {
                j++; 
            }
        }

        vector<int> ans;

        for (auto it : s) {
            ans.push_back(it);
        }

        return ans;
    }
};






    //  this is brute force approach
    //     vector<int> ans;

    //     for(int i = 0; i < nums1.size(); i++){
    //         for(int j = 0; j < nums2.size(); j++){
    //             if(nums1[i] == nums2[j]){
    //                 ans.push_back(nums1[i]);
    //             }
    //         }
    //     }
    //     sort(ans.begin(), ans.end());
    //    auto it = unique(ans.begin(), ans.end());
    //    ans.erase(it, ans.end()); 
    //     return ans;


