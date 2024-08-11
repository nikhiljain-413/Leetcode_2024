#define ll long long
ll MOD = 1e9+7;
class Solution {
public:
    ll dp[2001][51][51];
    ll solve(ll indx, vector<int>& nums, ll prev1, ll prev2){
        ll n = nums.size();
        if(indx==n){
            return 1;
        }
        if(dp[indx][prev1][prev2]!=-1){
            return dp[indx][prev1][prev2];
        }
        ll ans = 0;
        for(ll i=prev1;i<=nums[indx];i++){
            ll j = i;
            ll k = nums[indx]-j;
            if(j>=prev1 && k<=prev2){
                ans = (ans+solve(indx+1, nums, j,k))%MOD;
            }
        }
        return dp[indx][prev1][prev2] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0,nums,0,50);
    }
};