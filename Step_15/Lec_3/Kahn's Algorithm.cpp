class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adjList[V];
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        vector<int> indegree(V);
        
        for(int i=0;i<V;i++){
            for(auto x : adjList[i]){
                indegree[x]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto x : adjList[node]){
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }
        
        return ans;
    }
};