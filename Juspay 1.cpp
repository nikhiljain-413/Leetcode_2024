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
map<int, vector<pair<int,int>>> adj;
// map<int, bool> v;


int minimumCostSimplePath(int s, int d){
    map<int, int> dist;
    for(auto z: adj){
        dist[z.F] = INT_MAX;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if(dist[v] > dist[u]+weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[d];
}

int main(){
    // fast_io;
    int e,n;
    cin>>e;
    FOR(i,e){
        int f;cin>>f;
        adj[f] = vector<pi> ();
    }
    cin>>n;
    FOR(i,n) {
        int a,b,t;
        cin>>a>>b>>t;
        adj[a-1].pb({b-1, t});
    }
    int x,y;
    cin>>x>>y;
    cout<<minimumCostSimplePath(x-1, y-1)<<endl;
}