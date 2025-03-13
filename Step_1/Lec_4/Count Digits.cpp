class Solution {
    public:
      // Function to count the number of digits in n that evenly divide n
      int evenlyDivides(int n) {
          // code here
          int ans = 0;
          int num = n;
          while(n!=0){
              int temp = n%10;
              if((temp!=0) and (num%temp == 0)) ans+=1;
              n/=10;
          }
          return ans;
      }
  };