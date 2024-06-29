class Solution {
public:
    vector<set<int>> temp;
    void dfs(int node, vector<int> adj[], int nd){
        // cout<<node<<" ";
        for(auto ch : adj[node]){
            if(temp[ch].find(nd)!=temp[ch].end()) continue;
            temp[ch].insert(nd);

            dfs(ch, adj, nd);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        temp.resize(n, set<int>());
        vector<int> adj[n];
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            dfs(i, adj, i);
        }
        // dfs(0,adj,0);
        for(auto &t: temp){
            vector<int> tt(t.begin(), t.end());
            // for(auto it: t) tt.push_back(it);
            ans.push_back(tt);
        }
        return ans;
    }
};