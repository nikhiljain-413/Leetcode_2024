class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{0,1}};
    int n,m;
    void dfs(vector<vector<int>>& land, int i, int j, vector<vector<int>>& vis, int& k, int& l){
        vis[i][j] = 1;
        for(auto dir : dirs){
            int new_x = i+dir[0];
            int new_y = j+dir[1];
            if(new_x>=0 && new_y>=0 && new_x<n && new_y<m && land[new_x][new_y] && !vis[new_x][new_y]){
                k = max(k, new_x);
                l = max(l, new_y);
                dfs(land, new_x, new_y, vis, k,l);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(land[i][j] && !vis[i][j]){
                    int k = i;
                    int l = j;
                    dfs(land, i, j, vis, k, l);
                    ans.push_back({i, j, k, l});
                }
            }
        }
        return ans;
    }
};