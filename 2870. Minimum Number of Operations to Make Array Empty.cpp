class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num: nums){
            mp[num]++;
        }
        int ans = 0;
        for(auto pr: mp){
            if(pr.second<2) return -1;
            else{
                ans += (pr.second+2)/3;
            }
        }
        return ans;
    }
};