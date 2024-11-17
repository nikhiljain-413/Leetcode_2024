class Solution {
public:
    bool is_possible(int n, vector<int>& q, int mid){
        int stores = 0;
        for(auto qq: q){
            stores += qq/mid;
            stores += (qq%mid)?1:0;
        }
        return stores<=n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int low = 1;
        int high = *max_element(q.begin(), q.end());
        int ans;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(is_possible(n, q, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};