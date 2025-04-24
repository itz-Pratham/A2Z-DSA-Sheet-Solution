class Solution {
    public:
      // Function to perform selection sort on the given array.
      void selectionSort(vector<int> &arr) {
          // code here
          int n = arr.size();
          
          for(int i=0;i<n;i++){
              int msf = i;
              for(int j=i;j<n;j++){
                  msf = (arr[msf]<arr[j]) ? msf : j;
              }
              swap(arr[i],arr[msf]);
          }
      }
  };