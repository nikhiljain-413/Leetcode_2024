class Solution {
public:
    map<int,vector<int>> mp;
    // int ans = 0;
    int dfs(int node, int parent, int &ans){
        set<int> st;
        int tot_nodes = 1;
        for(auto child: mp[node]){
            if(child == parent) continue;
            int temp = dfs(child, node, ans);
            tot_nodes += temp;
            st.insert(temp);
        }
        if(st.size()<=1) ans++;
        return tot_nodes;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int ans = 0;
        dfs(0,-1,ans);
        return ans;
    }
};