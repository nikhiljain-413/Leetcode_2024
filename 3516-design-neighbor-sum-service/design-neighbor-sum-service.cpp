class neighborSum {
private:
    vector<vector<int>> grid;
public:
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;

    }
    
    int adjacentSum(int value) {
        int n = grid.size();
        int m = grid[0].size();
        int x,y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==value){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int sum = 0;
        if(y-1>=0) sum+= grid[x][y-1];
        if(y+1<m) sum+= grid[x][y+1];
        if(x-1>=0) sum+= grid[x-1][y];
        if(x+1<n) sum+= grid[x+1][y];
        return sum;
    }
    
    int diagonalSum(int value) {
        int n = grid.size();
        int m = grid[0].size();
        int x,y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==value){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int sum = 0;
        if(y-1>=0 && x-1>=0) sum+= grid[x-1][y-1];
        if(y+1<m && x-1>=0) sum+= grid[x-1][y+1];
        if(x+1<n && y-1>=0) sum+= grid[x+1][y-1];
        if(x+1<n && y+1<m) sum+= grid[x+1][y+1];
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */