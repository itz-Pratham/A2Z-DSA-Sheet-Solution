class Solution {
    public:
      int maxLen(vector<int>& arr) {
          // code here
          int n = arr.size();
          unordered_map<int,int> mp;
          int sum = 0;
          int ans = 0;
          mp[0] = -1;
          for(int i=0;i<n;i++){
              sum += arr[i];
              if(mp.find(sum) != mp.end()){
                  int subarray_dist = i-mp[sum];
                  ans = max(ans,subarray_dist);
              }
              else{
                  mp[sum] = i;
              }
          }
          return ans;
      }
  };