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
        map<int,vector<pair<int,int>>> mp; // col, {value, level}
        static bool cmp(pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        }
        void dfs(TreeNode* root, int col, int lvl){
            if(root == NULL){
                return;
            }
    
            mp[col].push_back({root->val,lvl});
            dfs(root->left, col-1, lvl+1);
            dfs(root->right, col+1, lvl+1);
    
            return;
        }
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            dfs(root, 0, 0);
            for(auto x : mp){
                sort(x.second.begin(), x.second.end(), cmp);
                vector<int> temp(x.second.size());
                for(int i=0;i<x.second.size();i++){
                    temp[i] = x.second[i].first;
                }
                ans.push_back(temp);
            }
            return ans;
        }
    };