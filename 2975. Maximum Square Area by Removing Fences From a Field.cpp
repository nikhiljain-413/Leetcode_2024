#define ll long long
class Solution {
public:
    ll MOD = 1000000007;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        
        hFences.push_back(m);
        vFences.push_back(n);
        hFences.push_back(1);
        vFences.push_back(1);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        hFences.erase(unique(hFences.begin(), hFences.end()), hFences.end());
        vFences.erase(unique(vFences.begin(), vFences.end()), vFences.end());
        
        set<ll> all_areas;
        for(ll i=0;i<vFences.size();i++){
            for(ll j=i+1;j<vFences.size();j++){
                all_areas.insert(vFences[j]-vFences[i]);
            }
        }
        ll ans = -1;
        for(ll i=0;i<hFences.size();i++){
            for(ll j=i+1;j<hFences.size();j++){
                ll area = hFences[j]-hFences[i];
                // cout<<area<<" ";
                if(all_areas.count(area)){
                    ans = max(ans, area*1ll*area);
                }
            }
        }
        // cout<<endl;
        return ans%MOD;
    }
};