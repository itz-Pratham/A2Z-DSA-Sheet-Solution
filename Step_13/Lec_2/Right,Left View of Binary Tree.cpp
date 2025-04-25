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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> ans;
            queue<TreeNode*> q;
            int temp = INT_MIN;
            q.push(root);
            q.push(NULL);
    
            if(root == NULL){
                return ans;
            }
            
            while(!q.empty()){
                TreeNode* cur = q.front();
                q.pop();
                
                if(cur == NULL){
                    ans.push_back(temp);
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    temp = cur->val;
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
            }
            return ans;
        }
    };