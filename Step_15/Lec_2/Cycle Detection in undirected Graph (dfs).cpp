class Solution {
  public:
    bool detect(int src, int parent, vector<int> adjList[], vector<int> &vis){
        vis[src] = 1;
        
        for(auto x : adjList[src]){
            if(!vis[x]){
                if(detect(x, src, adjList, vis)) return true;
            }
            else if(x != parent){
                return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adjList[V];
        
        int n = edges.size();
        int m = edges[0].size();
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i, -1, adjList, vis) == true)
                    return true;
            }
        }
        
        return false;
    }
};