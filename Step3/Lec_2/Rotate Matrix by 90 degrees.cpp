class Solution {
    public:
        void rotate(vector<vector<int>>& mat) {
            int n = mat.size();
    
            int top=0,left=0,bottom=n-1,right=n-1;
            int count = 0;
            while(top<bottom and left<right){
                for(int i=0;i<bottom-count;i++){
                    int t = mat[top][left+i];
                    mat[top][left+i] = mat[bottom-i][left];
                    mat[bottom-i][left] = mat[bottom][right-i];
                    mat[bottom][right-i] = mat[top+i][right];
                    mat[top+i][right] = t;
                }
                left++;
                top++;
                bottom--;
                right--;
                count++;
            }
        }
    };