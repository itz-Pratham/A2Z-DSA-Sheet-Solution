class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.length();
            int i=0;
            int j=n-1;
            string str = "";
            int cur_len = INT_MIN;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    int l=i,r=j;
                    while(l<=r){
                        if(s[l] == s[r]){
                            l++;
                            r--;
                        }
                        else
                            break;
                    }
                    if(l>r){
                        if(j-i+1 > cur_len){ 
                            str = s.substr(i,j-i+1);
                            cur_len = j-i+1;
                        }
                    }
                }
            }
            return str;
            
        }
    };