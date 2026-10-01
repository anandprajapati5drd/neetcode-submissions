class Solution {
public:
    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int wordIdx){
        if(wordIdx == word.size()){
            return true;
        }

        int rows = board.size();
        int cols = board[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols) return false;

        if(board[r][c] != word[wordIdx] || board[r][c] == '#') return false;

        char ch = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, r-1, c, word, wordIdx+1) || dfs(board, r+1, c, word, wordIdx+1) || dfs(board, r, c-1, word, wordIdx+1) || dfs(board, r, c+1, word, wordIdx+1);

        board[r][c] = ch;

        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    bool found = dfs(board, i, j, word, 0);
                    if(found) return true;
                }
            }
        }
        return false;
    }
};
