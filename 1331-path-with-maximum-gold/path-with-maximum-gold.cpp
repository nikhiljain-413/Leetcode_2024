class Solution {
public:
    int n,m;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(i<0||j<0||i==n||j==m||vis[i][j]||!grid[i][j]) return 0;
        vis[i][j]=1;
        int a = solve(i-1, j, grid, vis);
        int b = solve(i+1, j, grid, vis);
        int c = solve(i, j-1, grid, vis);
        int d = solve(i, j+1, grid, vis);
        vis[i][j]=0;
        return max({a, b, c, d})+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                vector<vector<int>> vis(n, vector<int> (m,0));
                ans = max(ans, solve(i,j,grid, vis));
            }
        }
        return ans;
    }
};