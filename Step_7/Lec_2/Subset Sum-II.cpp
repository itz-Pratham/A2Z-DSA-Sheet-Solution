class Solution {
    public:
        void recursion(vector<int> &nums, int n, int idx, vector<int> &temp, vector<vector<int>> &ans){
            if(idx == n){
                ans.push_back(temp);
                return;
            }
    
            temp.push_back(nums[idx]);
            recursion(nums, n, idx+1, temp, ans);
            temp.pop_back();
    
    
            // If we decide to exclude a number (like the first 2 in [1,2,2]), we should also skip all its duplicates to avoid generating duplicate subsets. For example, if we skip the first 2 and then pick the second one, we might end up generating the same subset twice (e.g., [1,2]). To avoid this, we skip over all duplicates in the exclusion path.
            while(idx + 1 < n && nums[idx] == nums[idx+1])
                idx++;
    
            recursion(nums, n, idx+1, temp, ans);
    
            // THIS IS AGAIN THE LOOPING OPTIMIZATION ... CAN TRY IT OUT ...
    
            // for(int i=idx;i<n;i++){
            //     if(i != idx && nums[i] == nums[i-1]) continue;
            //     temp.push_back(nums[i]);
            //     recursion(nums, n, i+1, temp, ans);
            //     temp.pop_back();
            // }
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> temp;
            int n = nums.size();
            sort(nums.begin(),nums.end());
            recursion(nums, n, 0, temp, ans);
            return ans;
        }
    };