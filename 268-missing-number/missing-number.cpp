class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int nums_sum = accumulate(nums.begin(), nums.end(), 0);
        return sum-nums_sum;
    }
};