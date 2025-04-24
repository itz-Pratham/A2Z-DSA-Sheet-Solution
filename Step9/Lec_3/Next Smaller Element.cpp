#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> A, int n1) {
    stack<int> st;
    vector<int> arr(n1,-1);
    st.push(A[0]);
    
    for(int i=1;i<n1;i++){
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        
        if(st.empty()) arr[i] = -1;
        else arr[i] = st.top();
        
        st.push(A[i]);
    }
    
    return arr;
}

int main(){
    vector<int> A = {3,2,1};
    int n1 = A.size();
    vector<int> ans = prevSmaller(A,n1);
    for(int i=0;i<n1;i++){
        cout<<ans[i]<<" ";
    }
    A = {4,5,2,10,8};
    n1 = A.size();
    cout<<endl;
    ans = prevSmaller(A,n1);
    for(int i=0;i<n1;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    
}