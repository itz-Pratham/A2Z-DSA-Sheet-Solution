// Here, I have solved the problem "Root to Leaf Paths" of GFG as it is almost similar problem ..

/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
      void dfs(Node* root, vector<vector<int>> &ans, vector<int> &temp){
          if(root == NULL){
              return;
          }
          
          if(root->left == NULL && root->right == NULL){
              temp.push_back(root->data);
              ans.push_back(temp);
              temp.pop_back();
              return;
          }
          
          temp.push_back(root->data);
          dfs(root->left, ans, temp);
          dfs(root->right, ans, temp);
          temp.pop_back();
          
          return;
      }
      vector<vector<int>> Paths(Node* root) {
          // code here
          vector<vector<int>> ans;
          vector<int> temp;
          if(!root) return ans;
          dfs(root, ans, temp);
          return ans;
      }
  };