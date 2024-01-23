#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool hasCommon(const std::string& s1, const std::string& s2) {
        int arr[26] = {0};

        for (char ch : s1) {
            if (arr[ch - 'a'] > 0)
                return true;
            arr[ch - 'a']++;
        }

        for (char ch : s2) {
            if (arr[ch - 'a'] > 0)
                return true;
        }

        return false;
    }

    int solve(int i, const std::vector<std::string>& arr, const std::string temp, int n) {
        if (i >= n) {
            return temp.length();
        }

        int left = 0;
        int right = 0;

        if (hasCommon(arr[i], temp)) {
            left = solve(i + 1, arr, temp, n);
        } else {
            left = solve(i + 1, arr, temp, n);

            right = solve(i + 1, arr, temp + arr[i], n); // I use over here call by value so do not need to remove the element in the temp string 
        }

        return std::max(left, right);
    }

    int maxLength(const std::vector<std::string>& arr) {
        std::string temp = "";
        int n = arr.size();

        return solve(0, arr, temp, n);
    }
};
