class Solution {
    public:
        int searchInsert(vector<int>& arr, int target) {
            int msf = 0;
            int l=0;
            int r=arr.size()-1;
    
            while(l<=r){
                int mid = l+(r-l)/2;
                if(arr[mid]==target){ 
                    return mid;
                }
                else if(arr[mid]>target) r = mid-1;
                else{
                    msf = mid;
                    l = mid+1;
                }
            }
    
            if(msf==0 and arr[0]>target) return msf;
            
            return msf+1;
        }
    };