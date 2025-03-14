class Solution {
    public:
      // Function to find pair with maximum sum
      int pairWithMaxSum(vector<int> &arr) {
          // Your code goes here
          int n = arr.size();
          int ans = INT_MIN;
          for(int i=0;i<n-1;i++){
              ans = max(ans,arr[i]+arr[i+1]);
          }
          return ans;
      }
  };