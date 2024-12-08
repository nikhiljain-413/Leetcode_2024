class Solution {
public:
    using info = tuple<int, bool, int>;
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<info> time(2*n);
        for(int i=0;i<n;i++){
            int s = events[i][0];
            int e = events[i][1];
            int v = events[i][2];
            time[2*i] = {s, 1, v};
            time[2*i+1] = {e+1, 0, v};
        }
        sort(time.begin(), time.end());
        int maxV = 0;
        int ans = 0;
        for(auto &[s, isStart, v] : time){
            if(isStart) ans = max(ans, v+maxV);
            else maxV = max(maxV, v);
        }
        return ans;
    }
};