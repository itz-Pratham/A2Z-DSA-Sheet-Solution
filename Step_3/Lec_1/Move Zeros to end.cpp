class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int c_z = 0;
            int p = 0;
            int n = nums.size();
    
            for(int i=0;i<n;i++){
                if(nums[i] == 0) c_z++;
                else{
                    nums[p] = nums[i];
                    p++;
                }
            }
            for(int k=n-c_z;k<n;k++){
                nums[k] = 0;
            }
        }
    };