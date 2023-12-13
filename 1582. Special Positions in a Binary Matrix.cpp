class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> last(m,0);
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    cnt++;
                    last[j]+=1;
                } 
            }
            mat[i].push_back(cnt);
        }
        mat.push_back(last);
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] && mat[i][m]==1 && mat[n][j]==1) cnt++;
            }
        }
        return cnt;
    }
};