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
        vector<vector<int>> levelOrder(TreeNode* root) {
            
            if(root == NULL){
                return {};
            }
            vector<vector<int>> ans;
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            vector<int> res;
    
            while(!q.empty()){
                TreeNode* f = q.front();
                q.pop();
    
                if(f == NULL){
                    ans.push_back(res);
                    res.clear();
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
    
                else{
                    res.push_back(f->val);
                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                }
            }
    
            return ans;
        }
    };