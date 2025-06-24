class Solution {
  public:
    bool dfs(int node, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto v : adjList[node]){
            if(!vis[v]){
                if(dfs(v, adjList, vis, pathVis)) return true;
            }
            else if(pathVis[v] == 1) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adjList[V];
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, adjList, vis, pathVis)) return true;
            }
        }
        
        return false;
    }
};