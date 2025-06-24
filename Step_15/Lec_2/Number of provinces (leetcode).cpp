class Solution {
    public:
        void dfs(int node, vector<vector<int>> isConnected, vector<int> &vis, int n){
            
            if(vis[node] == 1){
                return;
            }
    
            vis[node] = 1;
            
            for(int i=1;i<=n;i++){
                if(isConnected[node-1][i-1] == 1 && !vis[i]){
                    dfs(i, isConnected, vis, n);
                }
            }
    
            return;
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<int> vis(n+1,0);
            int ans = 0;
            int start = 1;
            
            for(int i=1;i<=n;i++){
                if(vis[i] == 0){
                    ans++;
                    dfs(i, isConnected, vis, n);
                }
            }
    
            return ans;
        }
    };