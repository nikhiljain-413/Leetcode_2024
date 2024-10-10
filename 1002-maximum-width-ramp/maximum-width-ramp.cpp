class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> vec;
        int n = nums.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        int min_indx = vec[0].second;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, vec[i].second-min_indx);
            min_indx = min(min_indx, vec[i].second);
        }
        return ans;
    }
};