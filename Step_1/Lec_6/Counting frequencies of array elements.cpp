class Solution {
    public:
      // Function to count the frequency of all elements from 1 to N in the array.
      vector<int> frequencyCount(vector<int>& arr) {
          vector<int> v(arr.size()+1,0);
          for(int i=0;i<arr.size();i++){
              v[arr[i]]++;
          }
          v.erase(v.begin());
          return v;
      }
  };