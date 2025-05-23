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
        vector<int> postorderTraversal(TreeNode* root) {
            stack<TreeNode*> st1;
            vector<int> ans;
            st1.push(root);
    
            if(root == NULL){
                return ans;
            }
    
            while(!st1.empty()){
                TreeNode* cur = st1.top();
                st1.pop();
                ans.push_back(cur->val);
                if(cur->left) st1.push(cur->left);
                if(cur->right) st1.push(cur->right);
            }
    
            reverse(ans.begin(),ans.end());
    
            return ans;
        }
    };