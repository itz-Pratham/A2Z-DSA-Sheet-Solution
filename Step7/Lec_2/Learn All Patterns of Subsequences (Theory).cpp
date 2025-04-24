class Solution {
    public:
    
      // although it's a recursion problem, it will give TLE .. so use DP for this ques.
      
      // void recursion(string &s0, int idx, string s, set<string> &res){
      //     if(idx == s0.size()){
      //         res.insert(s);
      //         return;
      //     }
  
      //     s.push_back(s0[idx]);
      //     recursion(s0,idx+1,s,res);
      //     s.pop_back();
  
      //     recursion(s0,idx+1,s,res);
      // }
      // string betterString(string s1, string s2) {
      //     // code here
      //     set<string> res1;
      //     set<string> res2;
      //     string str = "";
      //     recursion(s1,0,str,res1);
      //     recursion(s2,0,str,res2);
          
      //     return (res1.size() >= res2.size()) ? s1 : s2;
      // }
      
      int countDistinctSubsequences(string s) {
          int n = s.size();
          vector<int> dp(n + 1, 0);
          unordered_map<char, int> lastIndex;
          
          dp[0] = 1;
          
          for (int i = 1; i <= n; i++) {
              char ch = s[i - 1];
              dp[i] = 2 * dp[i - 1];
  
              if (lastIndex.find(ch) != lastIndex.end()) {
                  dp[i] -= dp[lastIndex[ch] - 1];
              }
  
              lastIndex[ch] = i;
          }
          
          return dp[n];
      }
      
      string betterString(string s1, string s2) {
          // code here
          return (countDistinctSubsequences(s1) >= countDistinctSubsequences(s2)) ? s1 : s2;
      }
  };
  