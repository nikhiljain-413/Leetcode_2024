class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                matrix[i][j] += min({matrix[i+1][j], j-1>=0?matrix[i+1][j-1]:INT_MAX, j+1<m?matrix[i+1][j+1]:INT_MAX});
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};