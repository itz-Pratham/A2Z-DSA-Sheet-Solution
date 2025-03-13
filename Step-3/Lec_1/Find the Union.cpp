class Solution {
    public:
      // a,b : the arrays
      // Function to return a list containing the union of the two arrays.
      vector<int> findUnion(vector<int> &a, vector<int> &b) {
          // Your code here
          // return vector with correct order of elements
          set<int> s;
          vector<int> v;
          for(int i=0;i<a.size();i++){
              s.insert(a[i]);
          }
          for(int i=0;i<b.size();i++){
              s.insert(b[i]);
          }
          for(int i : s){
              v.push_back(i);
          }
          return v;
      }
  };