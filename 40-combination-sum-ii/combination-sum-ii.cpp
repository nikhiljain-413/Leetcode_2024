class Solution {
public:
    // int dp[101][31];
    vector<vector<int>> ans;
    void solve(int i, vector<int>& candidates, int target, vector<int> &temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || i == candidates.size()) return;
        int prev = -1;
        for(int j=i;j<candidates.size();j++){
            if(candidates[j] == prev) continue;
            temp.push_back(candidates[j]);
            solve(j+1, candidates, target-candidates[j], temp);
            temp.pop_back();
            prev = candidates[j];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, candidates, target, temp);
        // vector<vector<int>> ret;
        // for(auto v: ans){
        //     ret.push_back(v);
        // }
        return ans;
    }
};