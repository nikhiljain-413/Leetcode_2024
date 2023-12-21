class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b){return a[0]<b[0];});
        int n = points.size();
        // vector<int> x_point;
        // for(int i=0;i<n;i++){
        //     x_point.push_back(points[i][0]);
        // }
        // sort(x_point.begin(), x_point.end());
        int mx = 0;
        for(int i=1;i<n;i++){
            mx = max(mx, points[i][0]-points[i-1][0]);
        }
        return mx;
    }
};