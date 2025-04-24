class Solution {
    public:
      int floorSqrt(int n) {
          // Your code goes here
          int l=0;
          int r=n;
          
          int ans = 0;
          
          while(l<=r){
              int mid = (l+r)/2;
              if(pow(mid,2) == n) return mid;
              else if(pow(mid,2) > n) r=mid-1;
              else{
                  ans = max(ans,mid);
                  l=mid+1;
              }
          }
          
          return ans;
      }
  };