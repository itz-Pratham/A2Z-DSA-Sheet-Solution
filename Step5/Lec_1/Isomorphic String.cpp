class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char,char> mp;
    
            for(int i=0;i<s.size();i++){
                if(mp.find(s[i])==mp.end()){
                    mp[s[i]] = t[i];
                }else{
                    if(mp[s[i]] == t[i]) continue;
                    else return false;
                }
            }
    
            unordered_map<char,char> mp2;
    
            for(int i=0;i<t.size();i++){
                if(mp2.find(t[i])==mp2.end()){
                    mp2[t[i]] = s[i];
                }else{
                    if(mp2[t[i]] == s[i]) continue;
                    else return false;
                }
            }
    
            return true;
        }
    };