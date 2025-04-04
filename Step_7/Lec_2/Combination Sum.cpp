class Solution {
    public:
        void recursion(vector<int>& candidates, int target, int n, int idx, vector<vector<int>> &ans, vector<int> &temp, int sum){
            
            if(sum == target){
                ans.push_back(temp);
                return;
            }
    
            if(sum >  target)
                return;
    
            if(idx == n) return;
    
            if(sum + candidates[idx] <= target){
                temp.push_back(candidates[idx]);
                recursion(candidates, target, n, idx, ans, temp, sum+candidates[idx]);
                temp.pop_back();
            }
    
            recursion(candidates, target, n, idx+1, ans, temp, sum);
    
            return;
    
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> temp;
            int n = candidates.size();
            recursion(candidates, target, n, 0, ans, temp, 0);
    
            return ans;
        }
    };