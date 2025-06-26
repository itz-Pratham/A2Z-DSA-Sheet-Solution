// User function Template for C++
class Solution {
  public:
    void dfs(int node, vector<pair<int,int>> adjList[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto x : adjList[node]){
            int temp = x.first;
            if(!vis[temp]){
                dfs(temp, adjList, vis, st);
            }
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adjList[V];
        stack<int> st;
        
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];
            adjList[u].push_back({v,cost});
        }
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adjList, vis, st);
            }
        }
        
        vector<int> dist(V,1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int cur = st.top();
            st.pop();
            
            for(auto x : adjList[cur]){
                int to_node = x.first;
                int wt = x.second;
                
                if(dist[to_node] > dist[cur] + wt){
                    dist[to_node] = dist[cur] + wt;
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
