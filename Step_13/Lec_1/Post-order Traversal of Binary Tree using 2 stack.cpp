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
            stack<TreeNode*> st2;
            vector<int> ans;
            st1.push(root);
    
            if(root == NULL){
                return ans;
            }
    
            while(!st1.empty()){
                TreeNode* cur = st1.top();
                st1.pop();
                st2.push(cur);
                if(cur->left) st1.push(cur->left);
                if(cur->right) st1.push(cur->right);
            }
    
            while(!st2.empty()){
                ans.push_back(st2.top()->val);
                st2.pop();
            }
    
            return ans;
        }
    };