class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dist = 0;
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n,0));
        vector<vector<int>> vis(m, vector<int>(n));

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    // ans[i][j] = 0;
                }
            }
        } 

        q.push({-1,-1});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == -1 && col == -1){
                dist++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
                continue;
            }

            ans[row][col] = dist;

            vector<int> dx = {-1,0,1,0};
            vector<int> dy = {0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0  && nrow <m && ncol >= 0 && ncol < n && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    // ans[nrow][ncol] = dist;
                    q.push({nrow,ncol});
                }
            }
        }

        return ans;
    }
};