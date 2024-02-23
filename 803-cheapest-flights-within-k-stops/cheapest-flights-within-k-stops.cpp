class Solution {
public:
    int dfs(int n, int src, int dest, int k, vector<pair<int,int>> adj[]){
        vector<int> vis(n,0);
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        //k, dist, src
        pq.push({0, 0, src});
        while(pq.size()){
            int k_used = pq.top()[0];
            int d = pq.top()[1];
            int s = pq.top()[2];
            pq.pop();
            if(k_used==k) continue;
            // vis[s] = 1;
            // cout<<s<<" ";
            for(auto nei_pr : adj[s]){
                int nei = nei_pr.first;
                int temp_dist = nei_pr.second;
                if(d+temp_dist<dist[nei]){
                    dist[nei] = d+temp_dist;
                    pq.push({k_used+1, dist[nei], nei});
                }
            }
        }
        if(dist[dest]==INT_MAX) return -1;
        return dist[dest];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<pair<int,int>> adj[n];
        for(auto flight: flights){
            int start = flight[0];
            int dest = flight[1];
            int time = flight[2];
            adj[start].push_back({dest, time});
        }
        return dfs(n, src, dest, k+1, adj);
    }
};