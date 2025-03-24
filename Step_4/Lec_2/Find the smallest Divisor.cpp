class Solution {
    public:
        int f(vector<int> &nums, int mid){
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum += ceil((double)nums[i]/mid);
            }
            return sum;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int l=1;
            int r=*max_element(nums.begin(), nums.end());;
            int ans = INT_MAX;
    
            while(l<=r){
                int mid = l + (r-l)/2;
                int sum = f(nums,mid);
                if(sum <= threshold){
                    ans = min(ans,mid);
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
    
            return ans;
        }
    };