class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> v(n,0);
            v[0] = nums[0];
            int ans = nums[0];
    
            for(int i=1;i<n;i++){
                v[i] = max(v[i-1]+nums[i],nums[i]);
                ans = max(ans,v[i]);
            }
            return ans;
        }
    };