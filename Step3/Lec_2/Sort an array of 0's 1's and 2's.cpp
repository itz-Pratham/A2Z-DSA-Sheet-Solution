class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int low = -1;
            int mid = 0;
            int high = n;
    
            while(mid<high){
                if(nums[mid]==1){
                    mid++;
                } else if(nums[mid] == 2){
                    high--;
                    swap(nums[mid],nums[high]);
                } else{
                    low++;
                    swap(nums[low],nums[mid]);
                    mid++;
                }
            }
        }
    };