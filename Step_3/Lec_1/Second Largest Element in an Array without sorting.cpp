class Solution {
    public:
      // Function returns the second
      // largest elements
      int getSecondLargest(vector<int> &arr) {
          // Code Here
          int n = arr.size();
          if(n<2) return -1;
          
          int large = INT_MIN;
          int s_large = INT_MIN;
          
          for(int i=0;i<n;i++){
              if(arr[i]>large){
                  s_large = large;
                  large = arr[i];
              } else if(arr[i]>s_large and (arr[i]!=large)){
                  s_large = arr[i];
              }else{
                  continue;
              }
          }
          
          return (s_large==INT_MIN)? -1 : s_large;
      }
  };