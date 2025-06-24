class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int initialColor = image[sr][sc];
            int m = image.size();
            int n = image[0].size();
            queue<pair<int,int>> q;
            vector<vector<int>> vis(m,vector<int>(n,0));
    
            vis[sr][sc] = 1;
            q.push({sr,sc});
    
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                image[row][col] = color;
                q.pop();
    
                int dRow[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
                int dCol[] = {0, 1, 0, -1};
    
                for(int k = 0; k < 4; k++) {
                    int newRow = row + dRow[k];
                    int newCol = col + dCol[k];
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && image[newRow][newCol] == initialColor && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
    
            }
    
            return image;
    
        }
    };