class Solution {
public:
    bool dfs(int node, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto v : adjList[node]){
            if(!vis[v]){
                if(dfs(v, adjList, vis, pathVis, check)) return true;
            }
            else if(pathVis[v] == 1) return true;
        }

        check[node] = 1;
        
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        int V = edges.size();
        vector<int> adjList[V];
        
        for(int i=0;i<V;i++){
            for(auto x : edges[i]){
                adjList[i].push_back(x);
            }
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> check(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adjList, vis, pathVis, check);
            }
        }

        vector<int> ans;

        for(int i=0;i<V;i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};