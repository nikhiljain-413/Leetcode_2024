
class Solution {
public:
    int cnt = 0;
    int dp[51][51][51];
    int MOD = 1e9+7;
    int solve(int i, int j, int m, int n, int mx){
        if(mx < 0){
            return 0;
        }
        if((i<0 || j<0 || i>=m || j>=n) && mx>=0){
            return 1;
        }
        if(dp[i][j][mx]!=-1){
            return dp[i][j][mx]%MOD;
        }
        int ans = 0;
        ans = (ans + solve(i,j+1,m,n,mx-1))%MOD;
        ans = (ans + solve(i,j-1,m,n,mx-1))%MOD;
        ans = (ans + solve(i+1,j,m,n,mx-1))%MOD;
        ans = (ans + solve(i-1,j,m,n,mx-1))%MOD;
        return dp[i][j][mx] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(startRow, startColumn, m, n, maxMove);
        return ans;
    }
};