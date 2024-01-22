#define ll long long
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ll n = nums.size();
        ll s1 = n*1ll*(n+1)/2;
        ll s2 = n*1ll*(n+1)*(2*n+1)/6;
        ll sum=0,sum2=0;
        for(auto num: nums){
            sum += num;
            sum2 += num*1ll*num;
        }
        ll x = s1 - sum;
        ll z = s2 - sum2;
        ll y = z/x;
        ll a = (x+y)/2ll;
        ll b = (y-x)/2ll;
        for(auto num: nums){
            if(num==a){
                return {(int)a,(int)b};
            }
            if(num==b){
                return {(int)b,(int)a};
            }
        }
        return {(int)b,(int)a};
    }
};