class Solution {
    public:
        void recursion(vector<int> &nums, int n, int idx, vector<int> temp, vector<vector<int>> &ans){
            if(idx == n){
                ans.push_back(temp);
                return;
            }
    
            temp.push_back(nums[idx]);
            recursion(nums, n, idx+1, temp, ans);
            temp.pop_back();
    
            recursion(nums, n, idx+1, temp, ans);
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> temp;
            int n = nums.size();
    
            recursion(nums, n, 0, temp, ans);
    
            return ans;
        }
    };