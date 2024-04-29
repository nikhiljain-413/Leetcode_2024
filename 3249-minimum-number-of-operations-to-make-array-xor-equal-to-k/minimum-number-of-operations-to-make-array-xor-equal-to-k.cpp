class Solution {
public:
    int difference(int a, int b){
        int cnt = 0;
        for(int i=0;i<31;i++){
            if((1<<i & a) == (1<<i&b)) continue;
            else cnt++;
        }
        return cnt;
    }
    int minOperations(vector<int>& nums, int k) {
        int xorr = 0;
        for(auto num: nums){
            xorr = xorr^num;
        }
        return difference(xorr, k);
    }
};
