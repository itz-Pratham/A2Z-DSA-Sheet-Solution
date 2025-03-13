class Solution {
    public:
      void reverseArray(vector<int> &arr) {
          if(arr.size()==1) return;
          for(int i=0;i<=ceil(arr.size()/2 - 1);i++){
              swap(arr[i],arr[arr.size()-1-i]);
          }
      }
  };