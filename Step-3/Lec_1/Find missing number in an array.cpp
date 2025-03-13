class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            // sort(nums.begin(),nums.end());
            // int i=0;
            // for(i=0;i<n;i++){
            //     if(nums[i] != i)
            //         return i;
            // }
            // return i;
    
            int sum = (n*(n+1))/2;
            int temp = 0;
            for(int i=0;i<n;i++){
                temp+= nums[i];
            }
            return sum-temp;
        }
    };