class Solution {
    public:
        int splitArray(vector<int>& nums, int k) {
            int l = *max_element(nums.begin(),nums.end());
            int r = accumulate(nums.begin(),nums.end(),0);
            int ans = 0;
            while(l<=r){
                int mid = (l+r)/2;
                int partitionNeeded = 1;
                int maxSum = 0;
                for(int i=0;i<nums.size();i++){
                    if(maxSum + nums[i] > mid){
                        partitionNeeded++;
                        maxSum = 0;
                    }
                    maxSum += nums[i];
                }
                if(partitionNeeded > k){
                     l = mid+1;
                }
                else{
                    ans = mid;
                    r = mid-1;
                }
            }
    
            return ans;
        }
    };