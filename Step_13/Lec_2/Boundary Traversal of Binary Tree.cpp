// This code is for GFG platform 
// Question name : Tree Boundary Traversal (Anticlockwise)

class Solution {
    public:
      void traversalLeft(Node* root, vector<int> &ans){
          if((root == NULL) || (root->left == NULL and root->right == NULL)){
              return;
          }
          
          ans.push_back(root->data);
          
          if(root->left)
              traversalLeft(root->left,ans);
          else
              traversalLeft(root->right,ans);
      }
      
      void traverseLeaf(Node* root,vector<int> &ans){
          if(root == NULL)
              return;
          
          if(root->left == NULL and root->right == NULL)
              ans.push_back(root->data);
              
          traverseLeaf(root->left, ans);
          traverseLeaf(root->right,ans);
      }
      
      void traverseReverseRight(Node* root, vector<int> &ans){
          if((root == NULL) || (root->left == NULL and root->right == NULL)){
              return;
          }
          
          if(root->right)
              traverseReverseRight(root->right,ans);
          else
              traverseReverseRight(root->left,ans);
              
          ans.push_back(root->data);
      }
      
      vector <int> boundary(Node *root)
      {
          //Your code here
          vector<int>ans;
          if(root == NULL)
              return ans;
              
          ans.push_back(root->data);
          
          // 1st part
          traversalLeft(root->left,ans);
          
          // 2nd part
          traverseLeaf(root->left,ans);
          traverseLeaf(root->right,ans);
          
          // 3rd part
          traverseReverseRight(root->right,ans);
          
          return ans;
      }
  };