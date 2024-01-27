#define ll long long
class Solution {
public:
    // int dp[1001][1001];
    int MOD = 1e9+7;
    // int solve(int n, int k){
    //     if(k==0){
    //         return 1;
    //     }
    //     if(dp[n][k]!=-1){
    //         return dp[n][k];
    //     }
    //     ll ans = 0;
    //     for(int i=0;i<=min(k, n-1);i++){
    //         ans = (ans + solve(n-1, k-i))%MOD;
    //     }
    //     return dp[n][k] = ans;
    // }
    int kInversePairs(int n, int k) {
        // return solve(n,k);
        vector<vector<int>> dp(n+1, vector<int> (k+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
                if(j>=i){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD)%MOD;
                }
            }
        }
        return dp[n][k];
    }
};