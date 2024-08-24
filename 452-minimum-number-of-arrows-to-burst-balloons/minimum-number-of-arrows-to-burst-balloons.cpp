class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1;
        int last = points[0][1];
        for(int i=1;i<points.size();i++){
            if(last>=points[i][0]){
                last = min(last, points[i][1]);
            }
            else{
                ans++;
                last = points[i][1];
            }
        }
        return ans;
    }
};