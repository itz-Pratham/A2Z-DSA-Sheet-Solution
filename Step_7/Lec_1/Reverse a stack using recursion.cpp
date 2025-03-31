class Solution{
    public:
        void reverseStack(vector<int> &v, int idx){
            if(idx == v.size()/2){
                return;
            }
            
            swap(v[idx],v[v.size()-1-idx]);
            reverseStack(v,idx+1);
        }
        void Reverse(stack<int> &s){
            vector<int> v;
            while(!s.empty()){
                v.push_back(s.top());
                s.pop();
            }
           
            reverseStack(v,0);
            
            for(int i=v.size()-1;i>=0;i--){
                s.push(v[i]);
            }
        }
    };