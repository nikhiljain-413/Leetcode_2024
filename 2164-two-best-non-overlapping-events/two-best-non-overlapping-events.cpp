class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> mx(n,0);
        mx[n-1] = events[n-1][2];
        for(int i=n-2;i>=0;i--){
            mx[i] = max(events[i][2], mx[i+1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int start = events[i][0];
            int end = events[i][1];
            int value = events[i][2];
            vector<int> to_find = {end, INT_MAX, INT_MAX};
            int indx = upper_bound(events.begin(), events.end(), to_find) - events.begin();
                ans = max(ans, value+ (indx<n?mx[indx]:0));
            
            // cout<<ans<<" ";
        }
        return ans;
    }
};