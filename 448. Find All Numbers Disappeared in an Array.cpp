class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> ans;
        st.insert(nums.begin(), nums.end());
        for(int i=1;i<=n;i++){
            if(st.count(i)==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};