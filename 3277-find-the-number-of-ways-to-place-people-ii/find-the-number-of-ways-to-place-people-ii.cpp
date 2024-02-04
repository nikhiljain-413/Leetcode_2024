class Solution {
public:
    bool static comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),comp);
        int n = points.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int mn = INT_MIN;
            for(int j=i+1;j<n;j++){
                if(points[j][1]>mn && points[j][1]<=points[i][1]){
                    ans++;
                    mn = max(mn, points[j][1]);
                }
            }
        }
        return ans;
    }
};