class Solution {
    public:
      // Complete this function
      void recur(int s, int &n){
          if(s == n+1){
              return; 
          }
          
          cout<<s<<" ";
          recur(s+1,n);
      }
      void printNos(int n) {
          recur(1, n);
      }
  };