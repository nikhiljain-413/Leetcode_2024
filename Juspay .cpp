#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define pl pair<ll, ll>
#define all(a) a.begin(), a.end()
#define mem(a,x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i,a) for(int i=0;i<a;i++)
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define trace2(x, y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io std::ios::sync_with_studio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
map<int, vector<int>> adj;
// map<int, bool> v;
bool bfs(int s, int t){
    // map<int,int> p;
    // for(auto x: adj){
    //     p[x.F] = -1;
    // }
    queue<int> q;
    q.push(s);
    // p[s] = s;
    map<int, bool> v;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(v[u]) continue;
        v[u] = 1;
        if(u==t) return true;
        for(auto x: adj[u]){
            if(!v[x]){
                q.push(x);
                // p[x] = u;
            }
        }
    }
    return false;
}

// bool dfs(int s, int d, int p){
//     if(s == d) return true;
//     else{
//         bool f = false;
//         for(auto m: adj[s]){
//             if(m!=p) f=dfs(m, d, s);
//             if(f) break;
//         }
//         return f;
//     }
// }

int main(){
    // fast_io;
    int e,n;
    cin>>e;
    FOR(i,e){
        int f;cin>>f;
        adj[f] = vector<int> ();
    }
    cin>>n;
    FOR(i,n) {
        int a,b;
        cin>>a>>b;
        adj[b-1].pb(a-1);
    }
    int x,y;
    cin>>x>>y;
    vector<int> ans;
    for(auto z: adj[y-1]){
        if(bfs(z,x-1)){
            ans.pb(z+1);
        }
    }
    for(auto z: ans) cout<<z<<" ";
}