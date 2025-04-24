class Solution {
    public:
        void recursion(int n, vector<string> &ans, string &cur, int open_cnt, int close_cnt){
            if(cur.size() == 2*n){
                ans.push_back(cur);
                return;
            }
    
            if(open_cnt < n){
                cur = cur + "(";
                recursion(n, ans, cur, open_cnt + 1, close_cnt);
                cur.pop_back();
            }
    
            if(close_cnt < open_cnt){
                cur = cur + ")";
                recursion(n, ans, cur, open_cnt, close_cnt + 1);
                cur.pop_back();
            }
        }
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            string cur = "";
            recursion(n, ans, cur, 0, 0);
            return ans;
        }
    };