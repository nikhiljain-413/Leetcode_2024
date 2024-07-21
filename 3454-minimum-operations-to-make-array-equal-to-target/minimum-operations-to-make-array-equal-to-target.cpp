#define ll long long
class Solution {
public:
    ll solve(ll start, ll end, vector<ll>& diff){
        ll height = 0;
        ll temp = 0;
        for(ll i=start;i<=end;i++){
            ll ht = abs(diff[i]);
            if(ht>height) temp+=(ht - height);
            height = ht;
        }
        // cout<<temp<<" ";
        return temp;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        ll n = nums.size();
        vector<ll> diff(n);
        for(ll i=0;i<n;i++){
            diff[i] = target[i] - nums[i];
        }
        vector<ll> indx;
        indx.push_back(0);
        for(ll i=1;i<n;i++){
            if(diff[i-1]*diff[i]>0) continue;
            else if(diff[i-1]*diff[i]<0){
                indx.push_back(i);
            }else{
                indx.push_back(i);

            }
        }
        indx.push_back(n);
        // for(auto it: indx) cout<<it<<" ";
        // cout<<endl;
        ll ans = 0;
        for(ll i=1;i<indx.size();i++){
            ans += solve(indx[i-1], indx[i]-1, diff);
        }
        return ans;
    }
};