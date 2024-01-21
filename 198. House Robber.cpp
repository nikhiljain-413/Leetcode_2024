class Solution {
public:
    int dp[102][102];
    int solve(int indx, int prev, vector<int>& nums){
        if(indx == nums.size()){
            return 0;
        }
        if(dp[indx][prev]!=-1){
            return dp[indx][prev];
        }
        int pick = 0;
        if(prev!=indx-1)
            pick = nums[indx] + solve(indx+1,indx,nums);
        int not_pick = solve(indx+1, prev, nums);
        return dp[indx][prev] = max(pick, not_pick);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0,101, nums);
    }
};