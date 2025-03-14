class Solution {
    public:
        bool check(vector<int>& nums) {
            int count = 0;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]) count++;
            }
    
            if(count>1) return false; // for count>1 consider case [3,6,10,1,8,9,9,8,9]
    
            if(nums[0]>=nums[nums.size()-1] and count!=0) count++;
            // for >= consider case [3,1,2] and [6,10,6]
            // for count!=0 consider case [1,1,1]
    
            return (count == 0 || count == 2) ? true : false;
        }
    };