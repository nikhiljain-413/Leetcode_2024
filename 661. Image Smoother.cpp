class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> temp = img;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum = img[i][j],cnt=1;
                if(i>=0 && j+1>=0 && i<n && j+1<m)sum+= img[i][j+1], cnt++;
                if(i>=0 && j-1>=0 && i<n && j-1<m)sum+= img[i][j-1], cnt++;
                if(i+1>=0 && j>=0 && i+1<n && j<m)sum+= img[i+1][j], cnt++;
                if(i-1>=0 && j>=0 && i-1<n && j<m)sum+= img[i-1][j], cnt++;
                if(i-1>=0 && j-1>=0 && i-1<n && j-1<m)sum+= img[i-1][j-1], cnt++;
                if(i-1>=0 && j+1>=0 && i-1<n && j+1<m)sum+= img[i-1][j+1], cnt++;
                if(i+1>=0 && j-1>=0 && i+1<n && j-1<m)sum+= img[i+1][j-1], cnt++;
                if(i+1>=0 && j+1>=0 && i+1<n && j+1<m)sum+= img[i+1][j+1], cnt++;
                temp[i][j] = sum/cnt;
            }
        }
        return temp;
    }
};