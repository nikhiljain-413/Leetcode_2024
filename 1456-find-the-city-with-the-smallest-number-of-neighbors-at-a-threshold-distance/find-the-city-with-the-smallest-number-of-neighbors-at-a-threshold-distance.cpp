class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1e5;
                }
            }
        }
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            dp[u][v] = min(dp[u][v], d);
            dp[v][u] = min(dp[v][u], d);
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int mx = n;
        int ans = n-1;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dp[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=mx){
                mx = cnt;
                ans = i;
            }
        }
        return ans;
    }
};