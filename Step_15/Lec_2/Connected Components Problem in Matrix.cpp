// See problem "200. Number of Islands" on LeetCode

class Solution {
    public:
        void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
            vis[row][col] = 1;
            queue<pair<int,int>> q;
            q.push({row,col});
            int m = grid.size();
            int n = grid[0].size();
            
            while(!q.empty()){
                row = q.front().first;
                col = q.front().second;
                q.pop();
                
                int dRow[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
                int dCol[] = {0, 1, 0, -1};
    
                for(int k = 0; k < 4; k++) {
                    int newRow = row + dRow[k];
                    int newCol = col + dCol[k];
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            int ans = 0;
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> vis(m, vector<int>(n,0));
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j] == '1' && !vis[i][j]){
                        ans++;
                        bfs(i, j, grid, vis);
                    }
                }
            }
            
            return ans;
        }
    };