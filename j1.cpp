#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int, vector<pair<int,int>>> adj;
map<int, int> nodes;
int bfs(int x, int y){
    map<int, int> dist;
    for(auto it: nodes){
        dist[it.first] = INT_MAX;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});
    dist[x]=0;
    while(!pq.empty()){
        
        int curr = pq.top().second;
        int wt = pq.top().first;
        // cout<<curr<<" "<<wt<<endl;
        pq.pop();
        for(auto nd: adj[curr]){
            int w = nd.second;
            int ndd = nd.first;
            if(dist[ndd]>dist[curr]+w){
                dist[ndd]=dist[curr]+w;
                pq.push({dist[ndd], ndd});
            }
        }
    }
    return dist[y];
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
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    // for(auto it: adj){
    //     cout<<it.first<<" ";
    //     for(auto nd: it.second){
    //         cout<<nd.first<<" "<<nd.second<<endl;
    //     }
    // }
    int x,y;
    cin>>x>>y;
    cout<< bfs(x,y)<<endl;
}