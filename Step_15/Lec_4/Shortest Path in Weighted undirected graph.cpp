class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;
        
        dist[1] = 0;
        pq.push({dist[1], 1});
        
        vector<pair<int,int>> adjList[n+1];
        
        for(int i=0;i<edges.size();i++){
            int from_node = edges[i][0];
            int to_node = edges[i][1];
            int cost = edges[i][2];
            adjList[from_node].push_back({to_node, cost});
            adjList[to_node].push_back({from_node,cost});
        }
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto x : adjList[node]){
                int adjNode= x.first;
                int wt = x.second;
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
        
    }
};