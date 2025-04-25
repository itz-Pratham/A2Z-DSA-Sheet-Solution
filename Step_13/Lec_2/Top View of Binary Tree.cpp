class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      map<int,pair<int,int>> mp;
      void dfs(Node* root, int col, int lvl){
          if(root == NULL){
              return;
          }
  
          if (mp.find(col) == mp.end()  || lvl < mp[col].second) {
              mp[col] = {root->data,lvl};
          }
          dfs(root->left, col-1, lvl+1);
          dfs(root->right, col+1, lvl+1);
  
          return;
      }
      vector<int> topView(Node *root) {
          // code here
          vector<int> ans;
          dfs(root, 0, 0);
          for(auto x : mp){
              ans.push_back(x.second.first);
          }
          return ans;
          
      }
  };