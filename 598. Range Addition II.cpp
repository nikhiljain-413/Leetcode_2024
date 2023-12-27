class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x_indx = m;
        int y_indx = n;
        for(auto op :ops){
            int i = op[0];
            int j = op[1];
            x_indx = min(x_indx, i);
            y_indx = min(y_indx, j);
        }
        return x_indx * y_indx;
    }
};