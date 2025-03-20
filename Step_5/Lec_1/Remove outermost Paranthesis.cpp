class Solution {
    public:
        string removeOuterParentheses(string s) {
            string str = "";
    
            int open = 0;
    
            for(int i=0;i<s.length();i++){
                if(s[i] == '('){
                    open++;
                    if(open>1){
                        str+=s[i];
                    }
                }
                else{
                    open--;
                    if(open != 0){
                        str += s[i];
                    }
                }
            }
    
            return str;
        }
    };