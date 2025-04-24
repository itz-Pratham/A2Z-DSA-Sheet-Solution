class Solution {
    public:
      // Function to sort the array using bubble sort algorithm.
      void bS(vector<int> &arr, int n, int idx){
          if(idx<0)
              return;
              
          for(int i=0;i<idx;i++){
              if(arr[i]>arr[i+1]){
                  swap(arr[i],arr[i+1]);
              }
          }
          
          bS(arr,n,idx-1);
      }
      void bubbleSort(vector<int>& arr) {
          // Your code here
          int n =arr.size();

          /*----------------------------------------- Iterative Bubble Sort ----------------------------------------*/
          /*
          for(int i=n-1;i>=0;i--){
              for(int j=0;j<i;j++){
                  if(arr[j]>arr[j+1]){
                      swap(arr[j],arr[j+1]);
                  }
              }
          }
          */
          
          bS(arr,n,n-1);
      }
  };