void reverseArray(int n, vector<int> &nums, vector<int> &temp, int index) {
    if (index == n) {
        return;
    }
    temp.push_back(nums[n - index - 1]); // last wala index ki value phela chahiye ha isliye kiya ha yeh
    reverseArray(n, nums, temp, index + 1);
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    vector<int> temp;
    int index = 0; 
    reverseArray(n, nums, temp, index);
    return temp;
}
