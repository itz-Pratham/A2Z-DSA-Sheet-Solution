class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> ans;
            stack<int> st;
        
            for(int i=0;i<asteroids.size();i++){
                while(!st.empty() && (st.top()>0 && asteroids[i]<0) && abs(st.top())<abs(asteroids[i])){
                    st.pop();
                }
                 if(!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                    if(abs(st.top()) == abs(asteroids[i])) {
                        st.pop();
                    }
                    continue;
                }
                st.push(asteroids[i]);
            }
    
            while(!st.empty()){
                int number = st.top();
                ans.push_back(number);
                st.pop();
            }
    
            reverse(ans.begin(),ans.end());
    
            return ans;
        }
    };