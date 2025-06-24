class Solution {
public:
    bool check(int start, vector<vector<int>>& graph, vector<int> &vis){
        int n = graph.size();

        for(auto x : graph[start]){
            if(vis[x] == -1){
                vis[x] = !vis[start];
                if(!check(x, graph, vis)) return false;
            }
            else if(vis[x] == vis[start]){
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(!check(i, graph, vis))
                    return false;
            }
        }
        return true;
    }
};