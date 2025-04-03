class Solution {
    public:
    
      // recursion won't work here due to constraint of arr size
      
      // void recursion(vector<int> &nums, int n, int idx, int &ans, int sum, int &target){
          
      //     if(idx == n){
      //         if(sum == target) ans++;
      //         return;
      //     }
  
      //     recursion(nums, n, idx + 1, ans, sum + nums[idx], target);
  
      //     recursion(nums, n, idx + 1, ans, sum, target);
      // }
      
      // int perfectSum(vector<int>& nums, int target) {
      //     // code here
      //     int ans = 0;
      //     int n = nums.size();
  
      //     recursion(nums, n, 0, ans, 0, target);
  
      //     return ans;
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