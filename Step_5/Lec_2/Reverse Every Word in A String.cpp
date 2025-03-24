class Solution {
    public:
        string reverseWords(string s) {
            string str = "";
            string temp = "";
    
            bool flag_i = false;
            bool flag_j = false;
    
            int i=0;
            int j=s.size()-1;
    
            while(i<=j){
                if(s[i]==' ')
                    i += 1;
                else
                    flag_i = true;
                
                
                if(s[j]==' ')
                    j -= 1;
                else
                    flag_j = true;
                
                
                if((flag_i==true) && (flag_j == true))
                    break;
            }
    
            for(int p=i;p<=j;p++){
                if(s[p]==' ' and s[p+1]!=' '){
                    str = temp + " " + str;
                    temp = "";
                }else if(s[p] == ' '){
                    continue;
                }
                else{
                    temp += s[p];
                }
            }
    
            str = temp + " " + str;
            str.pop_back();
    
            return str;
        }
    };