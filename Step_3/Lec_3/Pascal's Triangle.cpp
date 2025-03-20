class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;
            
            ans.push_back({1});
            if(numRows==1) return ans;
            
            ans.push_back({1,1});
            if(numRows==2) return ans;
            
            for(int i=2;i<numRows;i++){
                vector<int> temp(i+1,1);
                int left = 1;
                int right = i-1;
                while(left<=right){
                    vector<int> prev = ans[ans.size()-1];
                    temp[left] = prev[left-1]+prev[left];
                    left++;
                }
                ans.push_back(temp);
            }
    
            return ans;
        }
    };