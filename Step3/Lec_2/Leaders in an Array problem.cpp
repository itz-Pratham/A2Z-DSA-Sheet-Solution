class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> l;
        int n = arr.size();
        l.push_back(arr[n-1]);
        int max = arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=max){
                l.push_back(arr[i]);
                max = arr[i];
            }
        }
        reverse(l.begin(),l.end());
        return l;
    }
};