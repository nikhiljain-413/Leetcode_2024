class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(),arr.end()), arr.end());
    
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = lower_bound(arr.begin(), arr.end(), temp[i]) - arr.begin() + 1;
        }
        return ans;
    }
};