class Solution {
    public:
        int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();
    
            if(m > n/k) return -1;
    
            // applying binary search 
    
            int l = 1;
            int r = 1e9;
            int ans = 1;
    
            while(l<=r){
                int mid = (l+r)/2; // mid represents no. of days required ..
                int totalBouquetPossible = 0, count = 0;
    
                for(int i=0;i<n;i++){
                    if(bloomDay[i] <= mid) count++;
                    else count = 0;
    
                    if(count == k){
                        totalBouquetPossible += 1;
                        count = 0;
                    }
                }
    
                if(totalBouquetPossible >= m){
                    ans = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
    
            return ans;
        }
    };