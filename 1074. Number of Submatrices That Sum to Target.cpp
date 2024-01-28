class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int ans = 0;
        for(int cols = 0;cols<m;cols++){
            for(int cole=cols;cole<m;cole++){
                unordered_map<int,int> mp;
                mp[0]=1;
                int cnt = 0;
                for(int row=0;row<n;row++){
                    cnt+= matrix[row][cole] - (cols-1>=0?matrix[row][cols-1]:0);
                    int to_find = cnt-target;
                    if(mp.find(to_find)!=mp.end()) ans+=mp[to_find];
                    mp[cnt]++;
                }
            }
        }
        return ans;
    }
};