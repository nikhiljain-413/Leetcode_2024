class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int,int> dp;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(auto num: nums){
            dp[num+1] = dp[num]+1;
            dp[num] = dp[num-1]+1;
            ans = max(ans, dp[num+1]);
            ans = max(ans, dp[num]);
        }
        return ans;
    }
};