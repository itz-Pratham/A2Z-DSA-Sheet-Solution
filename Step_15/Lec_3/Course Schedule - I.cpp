class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        int V = numCourses;
        vector<int> adjList[V];
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[v].push_back(u);
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
        
        int cnt = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto x : adjList[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        
        if(cnt == numCourses) return true;
        
        return false;
    }
};