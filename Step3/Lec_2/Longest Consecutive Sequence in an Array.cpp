class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> st(nums.begin(), nums.end());
            int n = nums.size();
            int longest = 0;
            for (int num : nums) {
                if (st.find(num - 1) == st.end()) {  
                    int currentNum = num;
                    int count = 1;
                    while (st.erase(currentNum + 1)) {
                        currentNum++;
                        count++;
                    }
    
                    longest = max(longest, count);
                }
            }
            return longest;
        }
    };