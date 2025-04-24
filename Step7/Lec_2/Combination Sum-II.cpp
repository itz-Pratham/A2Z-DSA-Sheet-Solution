class Solution {
    public:
        void recursion(vector<int>& candidates, int target, int n, int idx, set<vector<int>> &ans, vector<int> &temp, int sum){
            
            if(sum == target){
                ans.insert(temp);
                return;
            }
    
            if(sum >  target)
                return;
    
            if(idx == n) return;
    
            for(int i=idx;i<n;i++){
    
                if(i > idx && candidates[i] == candidates[i-1]) continue; 
                // leave repeated elements but the condn (i > idx) is imp as it ensures that the element we are leaving is not the first element for the recursion call as we should pick it up no matter what ... maybe then check if it validates the condition or not but atleast no skipping it ..
    
                if(candidates[i] > target-sum) break;
    
                temp.push_back(candidates[i]);
                recursion(candidates, target, n, i+1, ans, temp, sum+candidates[i]);
                temp.pop_back();
            }
    
            return;
    
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            set<vector<int>> ans;
            vector<int> temp;
            sort(candidates.begin(),candidates.end());
            int n = candidates.size();
            recursion(candidates, target, n, 0, ans, temp, 0);
    
            vector<vector<int>> res;
            for(auto x :  ans){
                res.push_back(x);
            }
    
            return res;
        }
    };