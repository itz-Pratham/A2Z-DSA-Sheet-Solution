class Solution {
    public:
    
      // recursion won't work here due to constraint of arr size
      
      // int recursion(vector<int> &nums, int n, int idx, int sum, int &target){
          
      //     if(idx == n){
      //         if(sum == target) return 1;
      //         return 0;
      //     }
  
      //     int l = recursion(nums, n, idx + 1, sum + nums[idx], target);
  
      //     int r = recursion(nums, n, idx + 1, sum, target);
          
      //     return l+r;
      // }
      
      // int perfectSum(vector<int>& nums, int target) {
      //     // code here
      //     int n = nums.size();
  
      //     return recursion(nums, n, 0, 0, target);
      // }
      
      int perfectSum(vector<int>& nums, int target) {
          int n = nums.size();
          vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
          
          dp[0][0] = 1;
  
          for (int i = 1; i <= n; i++) {
              for (int j = 0; j <= target; j++) {
                  if (nums[i - 1] <= j) {
                      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                  } else {
                      dp[i][j] = dp[i - 1][j];
                  }
              }
          }
          return dp[n][target];
      }
  };
  