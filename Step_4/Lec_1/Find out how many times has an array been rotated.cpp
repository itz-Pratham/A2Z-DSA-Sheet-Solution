class Solution {
    public:
      int findKRotation(vector<int> &arr) {
          // Code Here
          
          // O(N) approach
          // int ans=1;
          // int i=0;
          // while(i<arr.size()-1 && arr[i]<arr[i+1]){
          //     i++;
          // }
          // if(i == arr.size()-1) return 0;
          // return ans+i;
          
          //O(logN) approach
          int res = 0;
          int n = arr.size();
          int low = 0;
          int high = n-1;
          
          while(low<high){
              int mid = (low+high)/2;
              if(arr[mid]<arr[low]){
                  high = mid;
              }else if(arr[mid]>arr[high]){
                  low = mid+1;
              }else{
                  break;
              }
          }
          return low;
      }
  };