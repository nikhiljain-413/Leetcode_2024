class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        // sort(nums.begin(), nums.end());
        int mx = 0;
        for(auto num: nums){
            mp[num]++;
            mx = max(mx, mp[num]);
        }
        vector<vector<int>> ans(mx);

        for(auto pr: mp){
            int num = pr.first;
            int cnt = pr.second;
            for(int i=0;i<cnt;i++){
                ans[i].push_back(num);
            }
        }
        return ans;
    }
};