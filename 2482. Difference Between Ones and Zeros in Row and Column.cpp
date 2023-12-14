class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ones(m,0);
        // vector<int> zeros(m,0);
        
        for(int i=0;i<n;i++){
            int cnt_o = 0;
            int cnt_z = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    cnt_o++;
                    ones[j]++;
                }
                // else{
                //     cnt_z++;
                //     zeros[j]++;
                // }
            }
            // grid[i].push_back(cnt_z);
            grid[i].push_back(cnt_o);
        }
        // vector<vector<int>> new_grid(n, vector<int> (m,0));
        // grid.push_back(zeros);
        grid.push_back(ones);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] =  2*grid[i][m]-m + 2*grid[n][j]-n;
            }
            grid[i].pop_back();
            // grid[i].pop_back();
        }
        // grid.pop_back();
        grid.pop_back();
        return grid;
    }
};