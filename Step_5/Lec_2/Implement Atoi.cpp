class Solution {
    public:
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
    
            while (i < s.length() && isdigit(s[i])){
    
                int digit = s[i]-'0';
    
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                    return (!flag) ? INT_MAX : INT_MIN;
                }
    
                ans = ans*10 + digit;
                i++;
            }
    
            if(flag == true) ans = -ans;
    
            return ans;
        }
    };