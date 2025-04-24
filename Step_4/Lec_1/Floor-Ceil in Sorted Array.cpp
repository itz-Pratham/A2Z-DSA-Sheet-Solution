class Solution {
    public:
      vector<int> getFloorAndCeil(int target, vector<int> &arr) {
          int floor = -1;
          int ceil = -1;
          int l=0;
          int r=arr.size()-1;
          sort(arr.begin(),arr.end());
  
          while(l<=r){
              int mid = l+(r-l)/2;
              if(arr[mid]==target){ 
                  floor = arr[mid];
                  ceil = arr[mid];
                  break;
              }
              else if(arr[mid]>target){
                  ceil = arr[mid];
                  r = mid-1;
              }
              else{
                  floor = arr[mid];
                  l = mid+1;
              }
          }
          
          // if(arr[msf]==target){
          //     while(arr[msf]==target) msf++;
          //     msf--;
          // }
          
          return {floor,ceil};
      }
  };