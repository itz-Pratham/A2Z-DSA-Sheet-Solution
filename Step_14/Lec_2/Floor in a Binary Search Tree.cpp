// GFG same ques

// Function to search a node in BST.
class Solution {

    public:
      int floor(Node* root, int input) {
          // Code here
          int ans = -1;
          while (root != NULL) {
              if (root->data == input) {
                  return root->data;
              }
              if (root->data < input) {
                  ans = root->data;
                  root = root->right;
              } else {
                  root = root->left;
              }
          }
          return ans;
      }
  };