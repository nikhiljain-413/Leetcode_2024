class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int start,end;
        int n = timeSeries.size();
        int i = 0;
        int ans = 0;
        while(i<n){
            start = timeSeries[i];
            end = timeSeries[i]+duration-1;
            i++;
            while(i<n && timeSeries[i]<=end){
                end = timeSeries[i]+duration-1;
                i++;
            }
            ans += end-start+1;
        }
        return ans;
    }
};