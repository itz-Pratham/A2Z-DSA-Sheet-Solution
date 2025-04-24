class Solution {
    public:
      string preToInfix(string pre_exp) {
          // Write your code here
          stack<string> st;
          unordered_set<char> operands = {'+','-','*','/','(',')','^'};
          
          for(int i=pre_exp.size()-1;i>=0;i--){
              if(operands.find(pre_exp[i]) == operands.end()){
                  st.push(string(1, pre_exp[i]));
              }
              else{
                  string t1 = st.top();
                  st.pop();
                  string t2 = st.top();
                  st.pop();
                  string new_str = "(" + t1 + pre_exp[i] + t2 + ")";
                  st.push(new_str);
              }
          }
          
          return st.top();
      }
  };