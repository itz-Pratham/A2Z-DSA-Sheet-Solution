class Solution {
    public:
        void r(string &s, int n, int idx, int &ans, bool &flag){
            if(idx >= n || !isdigit(s[idx])){
                return;
            }
    
            int digit = s[idx] - '0';
    
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                    ans =  (!flag) ? INT_MAX : INT_MIN;
                    return;
            }
    
            ans = ans*10 + digit;
    
            r(s,n,idx+1,ans,flag);
        }
    
        int myAtoi(string s) {
            int ans = 0;
            int i=0;
            bool flag = false;
    
            while(i < s.length() && s[i] == ' '){
                i++;
            }
    
            if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
                flag = (s[i] == '-') ? 1 : 0;
                i++;
            }
    
            r(s,s.length(),i,ans, flag);
    
            if((ans == INT_MAX && !flag) || (ans == INT_MIN && flag)) return ans;
    
            if(flag == true) ans = -ans;
    
            return ans;
        }
    };