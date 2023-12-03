class Solution {
public:
    int solve(vector<int> &v1, vector<int> &v2){
        return max(abs(v1[0] - v2[0]), abs(v1[1] - v2[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0;
        int n = points.size();
        for(int i=1;i<n;i++){
            sum += solve(points[i-1], points[i]);
        }
        return sum;
    }
};