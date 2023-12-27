class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
           mp[nums[i]]++;
        }
        int ans = 0;
        for(auto pr: mp){
            if(mp.find(pr.first-1)!=mp.end()){
                ans = max(ans, pr.second + mp[pr.first-1]);
            }
        }
        return ans;
    }
};