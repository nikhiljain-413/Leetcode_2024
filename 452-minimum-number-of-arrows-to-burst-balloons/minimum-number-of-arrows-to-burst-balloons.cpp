class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> v;
        int n = points.size();
        v.push_back(points[0]);
        for(int i=1;i<n;i++){
            if(v.back()[1]>=points[i][0]){
                v.back()[1] = min(v.back()[1], points[i][1]);
            }else{
                v.push_back(points[i]);
            }
        }
        return v.size();
    }
};