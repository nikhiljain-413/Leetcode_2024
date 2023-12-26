#define ll long long
class Solution {
public:
    ll dp[31][1001];
    ll MOD = 1000000007;
    ll solve(ll indx,ll n, ll k, ll target){
        if(indx == n){
            if(target==0) return 1;
            return 0;
        }
        if(dp[indx][target]!=-1){
            return dp[indx][target];
        }
        ll ans = 0;
        for(ll i=1;i<=k;i++){
            if(target-i>=0)
                ans = (ans + solve(indx+1, n, k, target-i))%MOD;
        }
        return dp[indx][target] = ans%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, k, target);
    }
};