//min no of nodes removal so that source can't reach destination


#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int, vector<int>> adj;
map<int, int> nodes;
bool bfs(int s, int x){
    map<int, int> vis;
    if(s==x) return true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(vis[curr]) continue;
        vis[curr] = 1;
        for(auto nd: adj[curr]){
            if(nd == x) return true;
            if(!vis[nd]){
                q.push(nd);
            }
        }
    }
    return false;
}
int32_t main()
{
    int v;cin>>v;
    for(int i=0;i<v;i++){
        int nd;cin>>nd;
        nodes[nd]=1;
    }
    int edges;cin>>edges;
    for(int i=0;i<edges;i++){
        int u,v;cin>>u>>v;
        adj[v].push_back(u);
    }
    int x,y;
    cin>>x>>y;
    set<int> st;
    for(auto nd: adj[y]){
        if(bfs(nd, x)){
            st.insert(nd);
        }
    }
    for(auto nd: st) cout<<nd<<" ";
}