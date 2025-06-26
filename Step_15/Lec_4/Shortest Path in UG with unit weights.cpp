class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adjList, int src) {
        queue<pair<int,int>> q;
        int n = adjList.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        q.push({src,dist[src]});
        
        while(!q.empty()){
            int cur = q.front().first;
            int wt = q.front().second;
            q.pop();
            
            for(auto x : adjList[cur]){
                if(dist[x] > wt + 1){
                    dist[x] = wt+1;
                    q.push({x, dist[x]});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};