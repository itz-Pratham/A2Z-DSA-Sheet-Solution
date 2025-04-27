// Here, I have solved the problem "Children Sum in a Binary Tree" of GFG as it is almost similar problem ..

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool dfs(Node* root){
        if(root == NULL){
            return true;
        }
        
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        
        int leftData = root->left ? root->left->data : 0;
        int rightData = root->right ? root->right->data : 0;
    
        if(root->data != leftData + rightData){
            return false;
        }
        
        return (dfs(root->left) && dfs(root->right));
    }
    int isSumProperty(Node *root) {
        // Add your code here
        return dfs(root);
    }
};