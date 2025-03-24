class Solution {
    public:
        int beautySum(string s) {
            int ans = 0;
            int n = s.length();
            for(int i=0;i<n-1;i++){
                unordered_map<char,int> mp;
                mp[s[i]]++;
                // cout<<s[i]<<" : "<<endl;
                for(int j=i+1;j<n;j++){
                    mp[s[j]]++;
                    int current_lowest = INT_MAX, current_highest = INT_MIN;
                    for(auto &p : mp){
                        current_lowest = min(current_lowest, p.second);
                        current_highest = max(current_highest, p.second);
                    }
                    // cout<<s[j]<<" "<<current_highest<<" "<<current_lowest<<" ";
                    ans += current_highest-current_lowest;
                    // cout<<ans<<endl;
                }
            }
            return ans;
        }
    };