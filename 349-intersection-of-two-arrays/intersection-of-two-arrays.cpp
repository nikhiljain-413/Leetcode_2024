class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        // nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        int i = 0,j=0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        while(i<n1 && j<n2){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;j++;
                while(i>0 && i<n1 && nums1[i]==nums1[i-1]){
                    i++;
                }
                while(j>0 && j<n2 && nums2[j]==nums2[j-1]){
                    j++;
                }
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};