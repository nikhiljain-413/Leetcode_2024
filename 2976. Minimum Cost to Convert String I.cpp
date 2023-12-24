#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source.size()!=target.size()){
            return -1;
        }
        ll dist[26][26];
        for(ll i=0;i<26;i++){
            for(ll j=0;j<26;j++){
                if(i==j){
                    dist[i][j] = 0;
                }else 
                dist[i][j] = 10000007;
            }
        }
        int n = cost.size();
        for(ll i=0;i<n;i++){
            ll u = original[i]-'a';
            ll v = changed[i]-'a';
            if(u==v) continue;
            dist[u][v] = min((int)dist[u][v], cost[i]);
        }
        // for(ll i=0;i<26;i++){
        //     for(ll j=0;j<26;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(ll k=0;k<26;k++){
            for(ll i=0;i<26;i++){
                for(ll j=0;j<26;j++){
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }
        // for(ll i=0;i<26;i++){
        //     for(ll j=0;j<26;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        ll ans = 0;
        ll m = source.size();
        for(ll i=0;i<m;i++){
            ll u = source[i]-'a';
            ll v = target[i]-'a';
            // cout<<dist[u][v]<<endl;
            if(dist[u][v]>=10000007){
                return -1;
            }
            ans += dist[u][v];
        }
        return ans;
    }
};