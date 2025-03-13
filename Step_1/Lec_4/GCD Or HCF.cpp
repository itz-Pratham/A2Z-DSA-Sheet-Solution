class Solution {
    public:
      vector<int> lcmAndGcd(int a, int b) {
          // code here
          int lcm = max(a,b);
          int gcd = 1;
          
          for(int i=2;i<=min(a,b);i++){
              if((a%i == 0) and (b%i==0)){
                  gcd = i;
              }
          }
          
          for(int i=max(a,b);true;i+=max(a,b)){
              if((i%a == 0) and (i%b==0)){
                  lcm = i;
                  break;
              }
          }
          
          return {lcm,gcd};
      }
  };