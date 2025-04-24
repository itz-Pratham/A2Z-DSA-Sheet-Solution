class Solution {
    public:
      string postToInfix(string exp) {
          // Write your code here
          stack<string> st;
          unordered_set<char> operands = {'+','-','*','/','(',')','^'};
          
          for(int i=0;i<exp.size();i++){
              if(operands.find(exp[i]) == operands.end()){
                  st.push(string(1, exp[i]));
              }
              else{
                  string t1 = st.top();
                  st.pop();
                  string t2 = st.top();
                  st.pop();
                  string new_str = "(" + t2 + exp[i] + t1 + ")";
                  st.push(new_str);
              }
          }
          
          return st.top();
      }
  };
  