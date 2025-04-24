class Solution {
    public:
      int nthRoot(int n, int m) {
          // Code here.
          
          // double root = pow(m,1.0/n);
          // int roundedRoot = round(root); 
          // return (pow(roundedRoot,n) == m) ? roundedRoot : -1;
          
          int l=1;
          int r=m;
          
          while(l<=r){
              int mid = (l+r)/2;
              if(pow(mid,n) == m) return mid;
              else if(pow(mid,n) > m) r= mid-1;
              else l=mid+1;
          }
          return -1;
      }
  };