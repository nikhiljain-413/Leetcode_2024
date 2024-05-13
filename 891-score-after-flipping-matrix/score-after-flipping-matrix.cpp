class Solution {
public:
    int n,m;
    int calculate(vector<vector<int>>& grid, int i){
        int a = 0;
        int pow2 = 1;
        for(int j=m-1;j>=0;j--){
            if(grid[i][j]){
                a+=pow2;
            }
            pow2*=2;
        }
        return a;
    }
    void reverse(vector<vector<int>>& grid, int k, int row){
        if(row){
            for(int j=0;j<m;j++){
                if(grid[k][j]) grid[k][j]=0;
                else grid[k][j] = 1;
            }
        }else{
            for(int i=0;i<n;i++){
                if(grid[i][k]) grid[i][k]=0;
                else grid[i][k] = 1;
            }
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            int a = 0;
            int b = 0;
            int pow2 = 1;
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]){
                    a+=pow2;
                }else b+=pow2;
                pow2*=2;
            }
            if(b>a) reverse(grid, i, 1);
        }
        for(int j=0;j<m;j++){
            int cnt_1 = 0;
            int cnt_0 = 0;
            for(int i=0;i<n;i++){
                if(grid[i][j]) cnt_1++;
                else cnt_0++;
            }
            if(cnt_0>cnt_1) reverse(grid, j, 0);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += calculate(grid, i);
        }
        return ans;
    }
};


