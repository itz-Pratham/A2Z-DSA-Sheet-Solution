class Solution {
    public:
  
      int findFloor(vector<int>& arr, int target) {
          // Your code here
          int msf = -1;
          int l=0;
          int r=arr.size()-1;
  
          while(l<=r){
              int mid = l+(r-l)/2;
              if(arr[mid]==target){ 
                  msf = mid;
                  break;
              }
              else if(arr[mid]>target) r = mid-1;
              else{
                  msf = mid;
                  l = mid+1;
              }
          }
          
          if(arr[msf]==target){
              while(arr[msf]==target) msf++;
              msf--;
          }
          
          return msf;
      }
  };