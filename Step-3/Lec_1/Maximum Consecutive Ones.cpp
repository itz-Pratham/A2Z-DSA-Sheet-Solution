class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int msf = 0;
            int cnt = 0;
            int n = nums.size();
            for(int i=0;i<n;i++){
                if(nums[i] == 1){
                    cnt++;
                }
                else{
                    msf = max(msf,cnt);
                    cnt=0;
                }
            }
            return max(msf,cnt);
        }
    };