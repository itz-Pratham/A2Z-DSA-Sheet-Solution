class Solution {
    public:
      string infixToPostfix(string& s) {
          // code here
          stack<char> st;
          string res = "";
          
          unordered_map<char, int> priority_map = {{'^',3}, {'*',2}, {'/',2}, {'+',1},
          {'-',1}};
          
          unordered_set<char> operands = {'+','-','*','/','(',')','^'};
          
          for(int i=0;i<s.size();i++){
              if(operands.find(s[i]) == operands.end()){
                  res.push_back(s[i]);        
              }    
              else{
                  if(s[i] == ')'){
                      while(st.top() != '('){
                          char topp = st.top();
                          res.push_back(topp);
                          st.pop();
                      }
                      st.pop();
                      continue;
                  }
                  else if(s[i] == '('){
                      st.push(s[i]);
                      continue;
                  }
                  else if(st.empty()){
                      st.push(s[i]);
                      continue;
                  }
                  else{
                      if(priority_map[st.top()] < priority_map[s[i]]){
                          st.push(s[i]);
                      }
                      else{
                          while(!st.empty() && st.top() != '(' &&
                            (priority_map[st.top()] >= priority_map[s[i]])){
                              char topp = st.top();
                              res.push_back(topp);
                              st.pop();
                          }
                          st.push(s[i]);
                      }
                  }
              }
          }
          
          while(!st.empty()){
              char topp = st.top();
              res.push_back(topp);
              st.pop();
          }
          
          return res;
      }
  };