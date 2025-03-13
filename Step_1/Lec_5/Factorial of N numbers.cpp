class Solution {
    public:
      // int fact(int n){
      //     if(n == 0){
      //         return 1;
      //     }
      //     return n * fact(n-1);
      // }
      // int fact(int X) {
      //   int ans = 1;
      //   for (int i = 1; i <= X; i++) {
      //       ans = ans * i;
      //   }
      //   return ans;
      // }
  
      vector<long long> factorialNumbers(long long n) {
          // Write Your Code here
          vector<long long> v;
          long long fact = 1;
          long long i = 1;
      
          while (fact <= n) {
              v.push_back(fact);
              i++; 
              fact *= i; 
          }
          return v;
      }
  };