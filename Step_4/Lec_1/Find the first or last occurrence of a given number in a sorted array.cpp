class Solution {
    public:
        vector<int> searchRange(vector<int>& arr, int target) {
            int msf = -1;
            int l=0;
            int r=arr.size()-1;
    
            while(l<=r){
                int mid = l+(r-l)/2;
                if(arr[mid]==target){ 
                    msf = mid;
                    break;
                }
                else if(arr[mid]>target) r = mid-1;
                else{
                    msf = mid;
                    l = mid+1;
                }
            }
    
            cout<<msf<<endl;
            
            int first,last;
            if(msf != -1){
                while(msf >= 0 && arr[msf]==target) msf--;
                first=msf+1;
                msf++;
                while(msf < arr.size() && arr[msf]==target) msf++;
                last=msf-1;
                msf--;
            }
            
            if(msf == -1 || arr[msf]!=target) return {-1,-1};
    
            return {first,last};
        }
    };