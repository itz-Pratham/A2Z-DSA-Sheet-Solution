class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        const int v = 26;
        vector<int> adjList[v];
        vector<int> indegree(v,0);
        vector<bool> used(v,0);
        
        for (const string& word : words) {
            for (char ch : word) {
                used[ch - 'a'] = true;
            }
        }
        
        for(int i=0;i<words.size()-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            if (s1.substr(0, len) == s2.substr(0, len) && s1.size() > s2.size()) {
                return ""; // Invalid input
            }
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adjList[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                    break;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0 && used[i]){
                q.push(i);
            }
        }
        
        string ans = "";
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += node+'a';
            
            for(auto x : adjList[node]){
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }

        if (ans.size() != count(used.begin(), used.end(), true)) return "";
        
        return ans;
    }
};