// You can find the question on 'GFG' 
// Link : "https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1"

class Solution {
    public:
      bool detect(int src, int V, vector<vector<int>> &adj, vector<int> &vis){
          queue<pair<int,int>> q;
          
          vis[src] = 1;
          q.push({src, -1});
          
          while(!q.empty()){
              int cur = q.front().first;
              int par = q.front().second;
              q.pop();
              
              for(auto x : adj[cur]){
                  if(!vis[x]){
                      vis[x] = 1;
                      q.push({x,cur});
                  }
                  else if(par != x){
                      return true;
                  }
              }
          }
          
          return false;
      }
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Code here
          vector<vector<int>> adj(V);
          
          for(auto e : edges){
              adj[e[0]].push_back(e[1]);
              adj[e[1]].push_back(e[0]); // because undirected
          }
          
          vector<int> vis(V,0);
          for(int i=0;i<V;i++){
              if(!vis[i]){
                  if(detect(i, V, adj, vis)) return true;
              }
          }
          return false;
      }
  };
  