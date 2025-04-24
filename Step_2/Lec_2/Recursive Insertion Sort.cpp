class Solution {
    public:
      // Please change the array in-place
      void iS(vector<int> &arr, int n, int idx){
          if(idx == n) return;
          
          int key = arr[idx];
          int i = idx-1;
          while(i>=0 && arr[i]>key){
              arr[i+1] = arr[i];
              i--;
          }
          arr[i+1] = key;
          
          iS(arr,n,idx+1);
      }
      void insertionSort(vector<int>& arr) {
          // code here
          int n= arr.size();
          
          /*-------------------- Iterative Insertion Sort --------------------*/
          /*
          for(int i=1;i<n;i++){
              int key = arr[i];  
              int j = i - 1;
              while (j >= 0 && arr[j] > key) {
                  arr[j + 1] = arr[j];
                  j--;
              }
              
              arr[j + 1] = key;
          }
          */
          
          iS(arr,n,1);
      }
  };
  