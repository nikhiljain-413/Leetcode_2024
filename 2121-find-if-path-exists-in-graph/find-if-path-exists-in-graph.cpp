class Solution {
public:
    bool dfs(vector<int> adj[], int sc, int ds, vector<int> &vis){
        if(sc == ds) return true;
        // bool present = false;
        vis[sc] = 1;
        for(auto ch: adj[sc]){
            if(!vis[ch]){
                if(dfs(adj, ch, ds, vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int sc, int ds) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(auto edge: edges){
            int u = edge[0];
             int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj, sc, ds, vis);
    }
};