class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k = k%n;
    
            vector<int> num(k,0);
            int p=0;
            for(int i=n-k;i<n;i++){
                num[p] = nums[i];
                p++;
            }
    
            for(int i=n-1;i>=k;i--){
                nums[i] = nums[i-k];
            }
    
            for(int i=0;i<k;i++){
                nums[i] = num[i];
            }
    
        }
    };