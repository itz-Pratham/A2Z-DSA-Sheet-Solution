class Solution {
    public:
      int longestSubarray(vector<int>& arr, int k) {
          // code here
          unordered_map<int,int> mp;
          int n = arr.size();
          int p_sum = 0;
          int ans = 0;
          int len = 0;
          for(int i=0;i<n;i++){
              p_sum += arr[i];
              if(p_sum == k){
                  ans = max(ans,i+1);
              }
              int rem = p_sum-k;
              if(mp.find(rem)!=mp.end()){
                  len = i-(mp[rem]);
                  ans = max(ans,len);
              }
              if(mp.find(p_sum) == mp.end()){
                  mp[p_sum] = i;
              }
          }
          return ans;
      }
  };