class Solution {
    public:
        bool isPalindrome(int x) {
    
            if(x<0) return false;
    
            int n = x;
    
            string s = to_string(x);
            int l = s.length();
    
            long long num = 0;
    
            while(l--){
                int temp = x%10;
                num = (num*10)+temp;
                x/=10;
            }
    
            return (num==n);
        }
    };