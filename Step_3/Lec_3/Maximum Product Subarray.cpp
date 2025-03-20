class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int left = INT_MIN;
            int right = INT_MIN;
            int prod = 1;
            int n = nums.size();
    
            for(int i=0;i<n;i++){
                prod *= nums[i];
                left = max(left,prod);
                if(prod == 0) prod = 1;
            }
    
            prod = 1;
    
            for(int i=n-1;i>=0;i--){
                prod *= nums[i];
                right = max(right,prod);
                if(prod == 0) prod = 1;
            }
    
            return max(left,right);
        }
    };