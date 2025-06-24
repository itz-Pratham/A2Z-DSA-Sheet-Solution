class Solution {
public:
    bool check(int start, vector<vector<int>>& graph, vector<int> &vis){
        int n = graph.size();
        queue<int> q;
        q.push(start);
        vis[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto x : graph[node]){
                if(vis[x] == -1){
                    vis[x] = vis[node] ? 0 : 1;
                    q.push(x);
                }
                else if(vis[x] == vis[node]){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                if(!check(i, graph, vis))
                    return false;
            }
        }
        return true;
    }
};