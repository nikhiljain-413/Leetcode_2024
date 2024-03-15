class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod1 = 1;
        int prod2 = 1;
        int cnt_zero = 0;
        int indx1 = 0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(num == 0){
                cnt_zero++;
                if(cnt_zero==2) break;
                indx1 = i;
                continue;
            }
            if(cnt_zero==0){
                prod1 *= num;
            }else{
                prod2 *= num;
            }
        }
        vector<int> v(n,0);
        if(cnt_zero==2) return v;
        if(cnt_zero==1){
            v[indx1] = prod1 * prod2;
            return v;
        }
        for(int i=0;i<n;i++){
            v[i] = prod1/nums[i];
        }
        return v;
    }
};