class Solution {
    public:
        static bool sortByVal(const pair<char, int> &a, const pair<char, int> &b) { 
            return (a.second > b.second); 
        } 
    
        string frequencySort(string s) {
            unordered_map<char,int> mp;
    
            for(int i=0;i<s.length();i++){
                mp[s[i]]++;
            }
    
            vector<pair<char,int>> v;
    
            for(auto x : mp){
                v.push_back(make_pair(x.first,x.second));
            }
    
            sort(v.begin(),v.end(),sortByVal);
    
            string str = "";
    
            for (auto &p : v) {
                str.append(p.second, p.first);  // Append character `p.first` `p.second` times
            }
    
            return str;
        }
    };