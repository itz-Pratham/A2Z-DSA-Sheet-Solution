class Solution {
    public:
        void recursion(int target, int n, int idx, vector<vector<int>> &ans, vector<int> &temp, int sum){
            
            if(temp.size() > n) return;
    
            if(temp.size() == n) {
                if(sum == target)
                    ans.push_back(temp);
                return;
            }
    
            for(int i=idx;i<10;i++){
                if(sum + i > target) break;
                temp.push_back(i);
                recursion(target, n, i+1, ans, temp, sum+i);
                temp.pop_back();
            }

            // THIS BELOW CODE ALSO WORKS BUT THE CURRENT IS MORE SPACE OPTIMIZED WITH A SINGLE RECURSION CALL
    
            // if(idx > 9) return;
    
            // if(sum + idx <= target){
            //     temp.push_back(idx);
            //     recursion(target, n, idx+1, ans, temp, sum+idx);
            //     temp.pop_back();
            // }
    
            // recursion(target, n, idx+1, ans, temp, sum);
    
            return;
    
        }
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> ans;
            vector<int> temp;
            recursion(n, k, 1, ans, temp, 0);
            return ans;
        }
    };