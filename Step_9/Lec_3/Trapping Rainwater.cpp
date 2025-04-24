class Solution {
    public:
        int trap(vector<int>& height) {
            int ans = 0;
            int n = height.size();
            int leftMax = INT_MIN;
            int rightMax = INT_MIN;
    
            int i=0;
            int j= n-1;
    
            while(i<=j){
                leftMax = max(leftMax,height[i]);
                rightMax = max(rightMax,height[j]);
    
                if(leftMax < rightMax){
                    ans += leftMax - height[i];
                    i++;
                }
                else{
                    ans += rightMax-height[j];
                    j--;
                }
            }
    
            return ans;
        }
    };