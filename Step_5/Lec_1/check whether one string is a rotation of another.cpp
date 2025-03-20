class Solution {
    public:
        bool rotateString(string s, string goal) {
            int n = s.size();
    
            if(n!=goal.size()) return false;
            
            for(int i=0;i<n;i++){
                char c = s[n-1];
                s.pop_back();
                s = c + s;
                if(s == goal) return true;
            }
    
            return false;
        }
    };