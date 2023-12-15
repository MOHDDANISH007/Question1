#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> startCount;
        map<string, int> destCount;

        for (int i = 0; i < paths.size(); ++i) {
            startCount[paths[i][0]]++;  // Count occurrences of the starting city
            destCount[paths[i][1]]++;   // Count occurrences of the destination city
        }

        for (const auto& it : destCount) {
            if (it.second == 1 && startCount[it.first] == 0) {
                return it.first;  // Return the destination city with count 1 and no starting occurrences
            }
        }

        return "";
    }
};


// Brute force approach

/*
for(int i=0; i<paths.size(); i++){
    string candidate = paths[i][1];
    bool good_city = true;

    for(int j=0; j<paths.size(); j++){
        if(candidate == paths[j][0]){
            good_city = false;
            break;
        }
    } 
    if(good_city){
        return candidate;
    }
    }
    return "";
}
*/
