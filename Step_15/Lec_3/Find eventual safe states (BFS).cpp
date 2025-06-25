class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        int v = edges.size();
        vector<int> adjRev[v];
        vector<int> indegree(v);

        for(int i=0;i<v;i++){
            for(auto x : edges[i]){
                // i->x converts to x -> i
                adjRev[x].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for(int i=0;i<v;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto x : adjRev[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};