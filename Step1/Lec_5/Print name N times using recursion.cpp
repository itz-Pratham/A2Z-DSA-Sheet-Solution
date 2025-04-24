class Solution {
    public:
    void recur(int n){
        if(n == 0){
              return;
          }
          
          cout<<"GFG ";
          n-=1;
          recur(n);
    }
      void printGfg(int N) {
          recur(N);
      }
  };