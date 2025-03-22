class Solution {
    public:
        int singleNonDuplicate(vector<int>& arr) {
            int l=0;
            int n = arr.size();
            int r = n-1;
    
            if(n==1) return arr[0];
    
            while(l<=r){
                int mid = (l+r)/2;
                if(mid%2 == 0){
                    if(mid != 0 && mid!= n-1){
                        if((arr[mid-1]!=arr[mid]) && (arr[mid]!=arr[mid+1])) return arr[mid];
                        else if(arr[mid-1]==arr[mid]) r = mid-1;
                        else l = mid+1;
                    }else if(mid == 0){
                        if(arr[mid]!=arr[mid+1]) return arr[mid];
                        else break;
                    }else{
                        if(arr[mid-1]!=arr[mid]) return arr[mid];
                        else break;
                    }
                }else{
                    if(mid != 0 && mid!= n-1){
                        if((arr[mid-1]!=arr[mid]) && (arr[mid]!=arr[mid+1])) return arr[mid];
                        else if(arr[mid-1]==arr[mid]) l = mid+1;
                        else r = mid-1;
                    }else if(mid == 0){
                        if(arr[mid]!=arr[mid+1]) return arr[mid];
                        else break;
                    }else{
                        if(arr[mid-1]!=arr[mid]) return arr[mid];
                        else break;
                    }
                }
            }
    
            return -1;
        }
    };