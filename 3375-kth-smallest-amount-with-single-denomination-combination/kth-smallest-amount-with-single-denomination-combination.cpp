#define ll long long
class Solution {
public:
    vector<pair<ll,ll>> odd_even_lcm;
    bool solve(ll mid, vector<int>& coins, int k){
        ll curr_pos = 0;
        for(auto pr: odd_even_lcm){
            if(pr.first){
                curr_pos += (mid/pr.second);
            }else{
                curr_pos -= (mid/pr.second);
            }
        }
        cout<<mid<<" "<<curr_pos<<endl;
        return curr_pos>=k;
    }
    void generate_subset(vector<int>& coins){
        ll n = coins.size();
        for(ll i=1;i<(1<<n);i++){
            ll lcmm = 1;
            ll cnt = 0;
            for(ll j=0;j<n;j++){
                if((1<<j)&i){
                    cnt++;
                    lcmm = lcm(lcmm, coins[j]);
                }
            }
            odd_even_lcm.push_back({cnt%2, lcmm});
        }
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        generate_subset(coins);
        ll low = coins[0];
        ll high = coins.back()*1ll*k;
        ll ans;
        while(low<=high){
            ll mid = low + (high - low)/2;
            if(solve(mid, coins, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
