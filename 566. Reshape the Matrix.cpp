class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(n*m != r*c){
            return mat;
        }
        int a=0,b=0;
        vector<vector<int>> ans(r, vector<int> (c,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[a][b] = mat[i][j];
                b++;
                if(b==c){
                    b = 0;
                    a++;
                }
            }
        }
        return ans;
    }
};