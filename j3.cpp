//find source can reach to destination or not


#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int, vector<int>> adj;
map<int, int> nodes;
bool bfs(int x, int y){
    map<int, int> vis;
    if(y==x) return true;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(vis[curr]) continue;
        vis[curr] = 1;
        for(auto nd: adj[curr]){
            if(nd == y) return true;
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
        adj[u].push_back(v);
    }
    int x,y;
    cin>>x>>y;
    cout<<bfs(x,y)<<endl;
}