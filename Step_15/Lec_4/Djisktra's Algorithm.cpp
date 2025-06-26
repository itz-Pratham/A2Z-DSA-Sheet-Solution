// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        pq.push({dist[src], src});
        
        vector<pair<int,int>> adjList[V];
        
        for(int i=0;i<edges.size();i++){
            int from_node = edges[i][0];
            int to_node = edges[i][1];
            int cost = edges[i][2];
            adjList[from_node].push_back({to_node, cost});
        }
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int cur_node = pq.top().second;
            pq.pop();
            
            for(auto x : adjList[cur_node]){
                int node = x.first;
                int wt = x.second;
                
                if(dis + wt < dist[node]){
                    dist[node] = dis + wt;
                    pq.push({dist[node],node});
                }
            }
        }
        
        return dist;
    }
};