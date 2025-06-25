class Solution {
  public:
    void dfs(int node, vector<int> adjList[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto x : adjList[node]){
            if(!vis[x]){
                dfs(x, adjList, vis, st);
            }
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adjList[V];
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adjList, vis, st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};