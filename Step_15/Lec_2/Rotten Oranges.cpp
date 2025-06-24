class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> vis(m,vector<int>(n,0));
            int ans = 0;
    
            queue<pair<int,int>> q;
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j] == 2){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
    
            q.push({-1,-1});
            
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                if(row == -1 && col == -1){
                    ans++;
                    q.pop();
                    if(!q.empty()){
                        q.push({-1,-1});
                    }
                    continue;
                }
                grid[row][col] = 2;
                q.pop();
                
                int dRow[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
                int dCol[] = {0, 1, 0, -1};
    
                for(int k = 0; k < 4; k++) {
                    int newRow = row + dRow[k];
                    int newCol = col + dCol[k];
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j] == 1){
                        return -1;
                    }
                }
            }
    
            return ans-1;
        }
    };