class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int mn = 24*60;
        vector<int> time(n);
        for(int i=0;i<n;i++){
            string s1 = timePoints[i];
            time[i] = ((s1[0]-'0')*10+s1[1]-'0')*60+(s1[3]-'0')*10+s1[4]-'0';
        }
        for(int i=0;i<n-1;i++){
            mn = min(mn, time[i+1] - time[i]);
        }
        mn = min(mn, 24*60-time[n-1]+time[0]);
        return mn;
    }
};