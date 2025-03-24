class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {

            // O(N)

            // int pos=0;
            // int n = arr.size();
            // int i=1;
            
            // for(int p=0;p<n;p++){
            //     if(arr[p] == i){
            //         i++;
            //     }else{
            //         while(arr[p]!=i){
            //             i++;
            //             pos++;
            //             if(pos == k) return i-1;
            //         }
            //         p--;
            //     }
            // }
    
            // return i+k-pos-1;


            // O(logN)

            int l=0;
            int r = arr.size()-1;

            while(l<=r){
                int mid = (l+r)/2;
                int missing_till_mid = arr[mid]-(mid+1);
                if(missing_till_mid<k) l=mid+1;
                else r=mid-1;
            }

            return k+r+1; // that this out yourself ... through visualization
            
        }
    };