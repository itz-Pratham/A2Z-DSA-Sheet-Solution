class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int l = 1;
            int r = 1e9;
            int ans = 0;
            while(l<=r){
                int mid = (l+r)/2;
                int hoursNeeded = 0;
                for(int i=0;i<piles.size();i++){
                    if(hoursNeeded < (INT_MAX-(piles[i]/mid)-1)){
                        hoursNeeded += (piles[i]/mid);
                        if(piles[i]%mid >= 1) hoursNeeded++;
                    }else{
                        hoursNeeded = INT_MAX;
                    }
                }
                if(hoursNeeded > h) l = mid+1;
                else{
                    ans = mid;
                    r = mid-1;
                }
                // cout<<l<<" "<<mid<<" "<<r<<endl;
            }
    
            return ans;
        }
    };