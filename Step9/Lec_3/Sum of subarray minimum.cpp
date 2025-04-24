class Solution {
    public:
        vector<int> nse(vector<int> arr){
            vector<int> ans(arr.size());
            stack<int> st;
    
            for(int i=arr.size()-1;i>=0;i--){
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
    
                ans[i] = (!st.empty()) ? st.top() : arr.size();
    
                st.push(i);
            }
    
            return ans;
        }
    
        vector<int> pse(vector<int> arr){
            vector<int> ans(arr.size());
            stack<int> st;
    
            for(int i=0;i<arr.size();i++){
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
    
                ans[i] = (!st.empty()) ? st.top() : -1;
    
                st.push(i);
            }
    
            return ans;
        }
    
    
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            vector<int> nextSmallerElement(n,n);
            vector<int> previousSmallerOrEqualElement(n,-1);
            
            int mod = 1e9+7;
    
            nextSmallerElement = nse(arr);
            previousSmallerOrEqualElement = pse(arr);
    
            int total = 0;
    
            for(int i=0;i<n;i++){
                int left = i-previousSmallerOrEqualElement[i];
                int right = nextSmallerElement[i]-i;
                total = (total + (1LL*left*right*arr[i])%mod)%mod;
            }
    
            return total;
        }
    };