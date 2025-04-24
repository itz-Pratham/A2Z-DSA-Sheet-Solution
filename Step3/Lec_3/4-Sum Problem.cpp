class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> ans;
            set<vector<int>> s;
            int n = nums.size();
            sort(nums.begin(),nums.end());
            for(int p=0;p<n-3;p++){
                for(int i=p+1;i<n-2;i++){
                    int j=i+1;
                    int k=n-1;
                    long long N_target = (long long)target - (long long)nums[p] - (long long)nums[i];
                    while(j < k){
                        if(nums[j] + nums[k] > N_target){
                            k--;
                        }
                        else if(nums[j] + nums[k] < N_target){
                            j++;
                        } 
                        else{
                            s.insert({nums[p],nums[i],nums[j],nums[k]});
                            k--;
                            j++;
                        }
                    }
                }
            }
            for(auto c : s){
                ans.push_back(c);
            }
            return ans;
        }
    };