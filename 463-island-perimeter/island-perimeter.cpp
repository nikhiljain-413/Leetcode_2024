class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis, int &temp){
        int n = grid.size();
        int m = grid[0].size();
        if(vis[i][j]) return;
        temp += 4;
        vis[i][j] = 1;
        int left_i = i;
        int left_j = j-1;
        int right_i = i;
        int right_j = j+1;
        int up_i = i-1;
        int up_j = j;
        int down_i = i+1;
        int down_j = j;
        if(left_j>=0 && grid[left_i][left_j]){
            temp--;
            dfs(grid, left_i, left_j, vis, temp);
        }
        if(up_i>=0 && grid[up_i][up_j]){
            temp--;
            dfs(grid, up_i, up_j, vis, temp);
        }
        if(right_j<m && grid[right_i][right_j]){
            temp--;
            dfs(grid, right_i, right_j, vis, temp);
        }
        if(down_i<n && grid[down_i][down_j]){
            temp--;
            dfs(grid, down_i, down_j, vis, temp);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && (!vis[i][j])){
                    cout<<i<<" "<<j<<endl;
                    int temp = 0;
                    dfs(grid, i, j, vis, temp);
                    ans += (temp);
                    cout<<ans<<endl;
                }
            }
        }
        return ans;
    }
};
