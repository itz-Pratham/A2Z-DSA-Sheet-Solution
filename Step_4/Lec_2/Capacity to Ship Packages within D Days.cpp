class Solution {
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int l = *max_element(weights.begin(), weights.end());
            int r = accumulate(weights.begin(), weights.end(), 0);
            int ans = r;
    
            while(l<=r){
                int mid = (l+r)/2;
                int sum = 0;
                int dayNeeded = 1;
                for(int i=0;i<weights.size();i++){
                    if (sum + weights[i] > mid) {  
                        dayNeeded++;
                        sum = 0;
                    }
                    sum += weights[i];
                }
    
                if(dayNeeded > days) l = mid+1;
                else{
                    ans = mid;
                    r = mid-1;
                }
            }
            return ans;
        }
    };