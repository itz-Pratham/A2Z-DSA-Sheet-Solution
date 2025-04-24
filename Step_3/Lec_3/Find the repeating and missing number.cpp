class Solution {
    public:
      vector<int> findTwoElement(vector<int>& arr) {
          // code here
          long long n = arr.size();
          
          long long sum_n = (n * (n + 1)) / 2;
          long long sum_sq_n = (n * (n + 1) * (2 * n + 1)) / 6;
          
          long long sum = 0, sum_sq = 0;
          
          for (long long num : arr) {
              sum += num;
              sum_sq += (num * num);
          }
          
          long long diff1 = sum - sum_n;  
          long long diff2 = sum_sq - sum_sq_n; 
          
          long long sum_diff = diff2 / diff1;  
          
          long long repeat = (diff1 + sum_diff) / 2;
          long long miss = sum_diff - repeat;
          
          return {(int)repeat, (int)miss};
          
      }
  };