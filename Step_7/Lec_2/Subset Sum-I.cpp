class Solution {
    public:
      void recursion(vector<int> &nums, int n, int idx, vector<int> &ans, int sum){
          
          if(idx == n){
              ans.push_back(sum);
              return;
          }
  
          recursion(nums, n, idx + 1, ans, sum + nums[idx]);
  
          recursion(nums, n, idx + 1, ans, sum);
      }
      
      vector<int> subsetSums(vector<int>& nums) {
          // code here
          vector<int> ans;
          int n = nums.size();
  
          recursion(nums, n, 0, ans, 0);
  
          return ans;
      }
  };