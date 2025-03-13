class Solution {
    public:
      int largest(vector<int> &arr) {
          int msf = INT_MIN;
          for(int i=0;i<arr.size();i++){
              if(msf < arr[i]) msf = arr[i];
          }
          return msf;
      }
  };