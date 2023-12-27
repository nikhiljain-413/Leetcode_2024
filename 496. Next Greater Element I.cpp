class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        // vector<int> next_greater(n, -1);
        unordered_map<int,int> mp;

        stack<int> st;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=-1;
            while(st.size() && nums2[st.top()]<nums2[i]){
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        for(auto num: nums1){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};