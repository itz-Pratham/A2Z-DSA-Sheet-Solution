class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> freq(n,0);
            freq[0]=nums[0];
            for(int i=1;i<n;i++){
                freq[i] = freq[i-1]+nums[i];
            }
            int cnt = 0;
            unordered_map<int,int> mp;
            for(int i=0;i<n;i++){
                if(freq[i]==k) cnt++;
                if(mp.find(freq[i]-k)!=mp.end()) cnt += mp[freq[i]-k];
                mp[freq[i]]++;
            }
            return cnt;
        }
    };