// You can find the problem on GFG named "DFS of graph"

class Solution {
    public:
      void dfs(int node, vector<vector<int>> adj, vector<int> &vis, vector<int> &ans){
          vis[node] = 1;
          ans.push_back(node);
          
          for(auto x : adj[node]){
              if(!vis[x]){
                  dfs(x, adj, vis, ans);
              }
          }
          
          return;
      }
      vector<int> dfs(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();
          vector<int> vis(n, 0);
          vector<int> ans;
          int start = 0;
          dfs(start, adj, vis, ans);
          return ans;
      }
  };
  