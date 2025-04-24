class Solution {
    public:
        int maxDepth(string s) {
            int msf = 0;
            int temp = 0;
            for(int i=0;i<s.size();i++){
                if(s[i] == '('){
                    temp++;
                    msf = max(msf,temp);
                }
                else if(s[i] == ')') temp--;
                else continue;
            }
            return msf;
        }
    };