class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> p;
            vector<int> neg;
            
            for(int i=0;i<n;i++){
                if(nums[i]>0) p.push_back(nums[i]);
                else neg.push_back(nums[i]);
            }
    
            int a=0,b=0;
            
            for(int i=0;i<n;i+=2){
                nums[i] = p[a];
                nums[i+1] = neg[b];
                a++;
                b++;
            }
            return nums;
        }
    };