class Solution {
public:
    vector<int> mapping;
    int convert(int num){
        string s = to_string(num);
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            ans = ans*10 + (mapping[s[i]-'0']);
        }
        // cout<<ans<<" ";
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        this->mapping = mapping;
        vector<pair<int,pair<int,int>>> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            v.push_back({convert(nums[i]), {i,nums[i]}});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(auto it: v){
            ans.push_back(it.second.second);
        }
        
        return ans;
    }
};