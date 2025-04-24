class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> s;
            int n = nums2.size();
            unordered_map<int,int> mp;
    
            for(int i=n-1;i>=0;i--){
                while(!s.empty() && s.top()<=nums2[i]){
                    s.pop();
                }
    
                if(s.empty()){
                    mp[nums2[i]] = -1;
                }
                else{
                    mp[nums2[i]] = s.top();
                }
    
                s.push(nums2[i]);
            }
    
            vector<int> res(nums1.size(),-1);
    
            for(int i=0;i<nums1.size();i++){
                res[i] = mp[nums1[i]];
            }
    
            return res;
        }
    };