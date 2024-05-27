class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<=n;i++){
            int no = nums.end() - lower_bound(nums.begin(), nums.end(), i);
            if(i==no) return i;
        }
        return -1;
    }
};