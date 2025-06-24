class Solution {
  public:
    void dfs(int row, int col, int brow, int bcol, vector<pair<int,int>> &temp, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[row][col] = 1;
        temp.push_back({row-brow, col-bcol});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, brow, bcol, temp, vis, grid);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int brow = i;
                    int bcol = j;
                    vector<pair<int,int>> temp;
                    dfs(i, j, brow, bcol, temp, vis, grid);
                    s.insert(temp);
                }
            }
        }
        
        return s.size();
    }
};
