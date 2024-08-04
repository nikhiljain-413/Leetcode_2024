class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int> ans;
        for(auto q: queries){
            adj[q[0]].push_back(q[1]);
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<int> dist(n,INT_MAX);
            dist[0]=0;
            pq.push({0,0});
            while(pq.size()){
                int node = pq.top().second;
                int distance = pq.top().first;
                pq.pop();
                for(auto it: adj[node]){
                    if(dist[it]>distance+1){
                        dist[it]=distance+1;
                        pq.push({distance+1, it});
                    }
                    if(it==n-1) break;
                }
            }
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};