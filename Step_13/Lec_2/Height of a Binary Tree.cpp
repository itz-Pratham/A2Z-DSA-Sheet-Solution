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
        int maxDepth(TreeNode* root) {
            if(root == NULL){
                return 0;
            }
    
            int ans = 0;
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
    
            while(!q.empty()){
                TreeNode* f = q.front();
                q.pop();
    
                if(f == NULL){
                    ans++;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
    
                else{
                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                }
            }
    
            return ans;
        }
    };