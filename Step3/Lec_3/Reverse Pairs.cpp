class Solution {
    public:
        int merge(vector<int> &nums, int l, int mid, int r){
            vector<int> temp;
            int left = l;
            int right = mid+1;
            int cnt = 0;
    
            int j=mid+1;
            for(int i=l;i<=mid;i++){
                while(j<=r && nums[i]>(2LL*nums[j])){ // This LL here is used for long long
                    j++;
                }
                cnt += j-(mid+1);
            }
    
            while(left<=mid && right<=r){
                if(nums[left]<=nums[right]){
                    temp.push_back(nums[left]);
                    left++;
                } else{
                    temp.push_back(nums[right]);
                    right++;
                }
            }
    
            while(left<=mid){
                temp.push_back(nums[left]);
                left++;
            }
    
            while(right<=r){
                temp.push_back(nums[right]);
                right++;
            }
    
            for(int i=l;i<=r;i++){
                nums[i] = temp[i-l];
            }
    
            return cnt;
        }
        int mS(vector<int> &nums, int l, int r){
            int cnt = 0;
            if(l>=r) return cnt;
            int mid = (l+r)/2;
            cnt += mS(nums,l,mid);
            cnt += mS(nums,mid+1,r);
            cnt += merge(nums,l,mid,r);
            return cnt;
        }
        int reversePairs(vector<int>& nums) {
            return mS(nums,0,nums.size()-1);
        }
    };