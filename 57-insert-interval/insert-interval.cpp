class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<int> find =  {newInterval[0], INT_MAX};
        int indx = upper_bound(intervals.begin(), intervals.end(), find) - intervals.begin();
        for(int i=0;i<indx;i++){
            ans.push_back(intervals[i]);
        }
        if(ans.size()==0) ans.push_back(newInterval);
        else{
            if(newInterval[0]<=ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], newInterval[1]);
            }else{
                ans.push_back(newInterval);
            }
        }
        // ans.push_back(newInterval);
        for(int i=indx;i<n;i++){
            if(intervals[i][0]<=ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};