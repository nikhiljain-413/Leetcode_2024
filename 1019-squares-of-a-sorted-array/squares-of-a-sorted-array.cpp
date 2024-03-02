class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        for(int i=0;i<n;i++){
            int num = nums[i]*nums[i];
            auto it = lower_bound(ret.begin(), ret.end(), num);
            if(it== ret.end()){
                ret.push_back(num);
            }else{
                ret.insert(it, num);
            }
        }
        return ret;
    }
};