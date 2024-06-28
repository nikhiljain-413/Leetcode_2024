#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<ll,ll> mp;
        for(auto r: roads){
            mp[r[0]]++;
            mp[r[1]]++;
        }
        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        multiset<ll> st;
        for(auto it: mp){
            st.insert(it.second);
        }
        ll ans = 0;
        for(auto it = st.rbegin();it!=st.rend();it++){
            // cout<<it<<" ";
            ans+=*it * n;
            n--;
        }
        return ans;
    }
};
