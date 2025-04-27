/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* lca(TreeNode* root, int p, int q){
    
            if(!root) return NULL;
    
            if(root->val == p || root->val == q) return root;
    
            TreeNode* le = lca(root->left, p, q);
            TreeNode* re = lca(root->right, p, q);
    
            if(le != NULL && re != NULL) return root;
            if(le != NULL && re == NULL) return le;
            if(re != NULL && le == NULL) return re;
    
            return NULL;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return lca(root, p->val, q->val);
        }
    };