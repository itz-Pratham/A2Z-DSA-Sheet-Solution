class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n = nums.size();
    
            vector<int> num;
    
            for(int i=0;i<n-1;i++){
                if(nums[i]!=nums[i+1]){
                    num.push_back(nums[i]);
                }
            }
    
            num.push_back(nums[n-1]);
    
            int s = num.size();
    
            for(int i=0;i<s;i++){
                nums[i] = num[i];
            }
    
            return s;
        }
    };