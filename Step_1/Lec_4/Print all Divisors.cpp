// User function Template for C++
class Solution {
    public:
      int sumOfDivisors(int n) {
          // Write Your Code here
          int ans = 0;
          for(int i=1;i<=n;i++){
              for(int j=1;j<=i;j++){
                  if(i%j == 0) ans+= j;
              }
          }
          return ans;
      }
  };