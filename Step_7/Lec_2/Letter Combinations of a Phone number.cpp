class Solution {
    public:
        void recursion(string &digits, int n, vector<string> &ans, string &temp, int idx, vector<string> &keypad){
            if(idx == n){
                if(temp.size() == 0) return;
                ans.push_back(temp);
                return;
            }
    
            int number = digits[idx]-'0';
    
            if(number == 0 || number == 1){
                recursion(digits, n, ans, temp, idx+1, keypad);
            }
    
            string validHere = keypad[number];
    
            for(char c : validHere){
                temp.push_back(c);
                recursion(digits, n, ans, temp, idx+1, keypad);
                temp.pop_back();
            }
    
        }
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            string temp = "";
            vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            int n = digits.size();
            recursion(digits, n, ans, temp, 0, keypad);
            return ans;
        }
    };