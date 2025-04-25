/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int findMax(TreeNode* root, int &maxi){
            if(root == NULL) return 0;
    
            int leftPathSum = max(0,findMax(root->left, maxi));
            int rightPathSum = max(0,findMax(root->right, maxi));
    
            maxi = max(maxi, root->val + rightPathSum + leftPathSum); // overall maximum value
    
            return root->val + max(leftPathSum, rightPathSum); // Maximum pathSum for the node
        }
        int maxPathSum(TreeNode* root) {
            int maxi = INT_MIN;
            findMax(root, maxi);
            return maxi;
        }
    };