class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]) continue;
                if(grid[i][j]){
                    ans+=4;
                }
                if(i-1>=0 && grid[i-1][j]){
                    ans-=1;
                }
                if(i+1<n && grid[i+1][j]){
                    ans-=1;
                }
                if(j-1>=0 && grid[i][j-1]){
                    ans-=1;
                }
                if(j+1<m && grid[i][j+1]){
                    ans-=1;
                }
                
            }
        }
        return ans;
    }
};