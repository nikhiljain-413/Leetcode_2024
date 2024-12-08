
class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = -1;
        for(int i=0;i<n-3;i++){
            if(points[i][0] != points[i+1][0]) continue;
            for(int j=i+2;j<n-1;j++){
                if(points[j][0] != points[j+1][0] || points[i][1] != points[j][1] || points[i+1][1] != points[j+1][1])
                    continue;
                bool flag = false;
                int bottom_x = points[i][0];
                int bottom_y = points[i][1];
                int top_x = points[j+1][0];
                int top_y = points[j+1][1];    
                for(int k=i+2;k<j;k++){ 
                    int x = points[k][0],y = points[k][1];
                             
                    if((bottom_x<x && x<top_x && bottom_y<y && y<top_y) || ((x==bottom_x || x==top_x) && bottom_y<=y && y<=top_y) 
                        || ((y==top_y || y==bottom_y) && bottom_x<=x && x<=top_x)){
                            flag = true;
                            break;
                        } 
                    
                }
                if(flag) continue;
                ans = max(ans, (top_x - bottom_x)*(top_y-bottom_y));
            }
        }
        return ans;
    }
};

