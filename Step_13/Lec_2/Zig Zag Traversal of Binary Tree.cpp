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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            vector<int> res;
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            int dir = 1;
    
            if(!root){
                return ans;
            }
    
            while(!q.empty()){
                TreeNode* temp = q.front();
                q.pop();
    
                if(temp == NULL){
                    if(dir == 1) ans.push_back(res);
                    else{ 
                        reverse(res.begin(),res.end());
                        ans.push_back(res);
                    }
                    res.clear();
                    dir = -dir;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    res.push_back(temp->val);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    // if(dir == 1){
                    //     if(temp->right) q.push(temp->right);
                    //     if(temp->left) q.push(temp->left);
                    // }
                    // else{
                    //     if(temp->left) q.push(temp->left);
                    //     if(temp->right) q.push(temp->right);
                    // }
                }
            }
    
            return ans;
        }
    };