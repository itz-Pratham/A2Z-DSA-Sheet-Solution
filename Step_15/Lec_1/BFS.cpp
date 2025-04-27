// You can find the problem on GFG named "BFS of graph"

class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfs(vector<vector<int>> &adj) {
          // Code here
          int n = adj.size();
          queue<int> q;
          vector<int> vis(n,0);
          int node = 0;
          vector<int> bfs;
          
          vis[node] = 1;
          q.push(node);
          
          while(!q.empty()){
              node = q.front();
              q.pop();
              bfs.push_back(node);
              
              for(auto x : adj[node]){
                  if(!vis[x]){
                      vis[x] = 1;
                      q.push(x);
                  }
              }
          }
          
          return bfs;
      }
  };