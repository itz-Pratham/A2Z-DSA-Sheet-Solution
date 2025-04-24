class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_map<int,int> mp;
            int n = nums.size();
            for(int i=0;i<n;i++){
                mp[nums[i]]++;
            }
            for(auto ip : mp){
                if(ip.second == 1) return ip.first;
            }
            return -1;
        }
    };