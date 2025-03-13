class Solution {
    public:
      void recur(int n){
          if(n == 0){
              return; 
          }
          
          cout<<n<<" ";
          n-=1;
          recur(n);
      }
      void printNos(int N) {
          // code here
          recur(N);
      }
  };