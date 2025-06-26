class Solution {
public:
    bool rec(vector<vector<char>>& board, string word, int idx, int i, int j){
        if(idx == word.size()) 
            return true;

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = ' ';  // updating the board for marking visited

        bool cur = rec(board, word, idx+1, i-1,j) ||
                   rec(board, word, idx+1, i,j-1) || 
                   rec(board, word, idx+1, i,j+1) ||
                   rec(board, word, idx+1, i+1,j);

        board[i][j] = temp; // backtracking

        return cur;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(rec(board,word,0,i,j)) return true;
                }
            }
        }

        return false;
    }
};