class Solution {
    public:
      string postToPre(string post_exp) {
          // Write your code here
          stack<string> st;
          unordered_set<char> operands = {'+','-','*','/','(',')','^'};
          
          for(int i=0;i<post_exp.size();i++){
              if(operands.find(post_exp[i]) == operands.end()){
                  st.push(string(1, post_exp[i]));
              }
              else{
                  string t1 = st.top();
                  st.pop();
                  string t2 = st.top();
                  st.pop();
                  string new_str = post_exp[i] + t2 + t1;
                  st.push(new_str);
              }
          }
          
          return st.top();
      }
  };