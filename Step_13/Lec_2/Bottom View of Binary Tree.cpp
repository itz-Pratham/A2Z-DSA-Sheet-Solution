class Solution {
    public:
      vector<int> bottomView(Node *root) {
          // Your Code Here
          vector<int> ans;
          map<int,int> mp;
          queue<pair<Node*,int>> q;
          q.push({root, 0});
          
          while(!q.empty()){
              pair<Node*,int> p = q.front();
              q.pop();
              Node* cur = p.first;
              int col = p.second;
              
              mp[col] = cur->data;
              if(cur->left) q.push({cur->left, col-1});
              if(cur->right) q.push({cur->right, col+1});
          }
          
          for(auto x : mp){
              ans.push_back(x.second);
          }
          return ans;
      }
  };