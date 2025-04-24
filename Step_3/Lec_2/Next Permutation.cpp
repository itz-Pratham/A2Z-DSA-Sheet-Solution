class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int i=n-1;
            
            while(i>0 and nums[i-1]>=nums[i])
                i--;
            
            if(i==0){
                return reverse(nums.begin(),nums.end());
            }
    
            int j=n-1;
    
            while(j>0 and nums[j]<=nums[i-1]) j--;
    
            swap(nums[i-1],nums[j]);
    
            reverse(nums.begin()+i,nums.end());
        }
    };