class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, int delrow[], int delcol[], int &count){
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;

        for(int i=0; i<4; i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !visited[newrow][newcol] && grid[newrow][newcol] == 1){
                visited[newrow][newcol] = 1;
                count++;
                dfs(newrow, newcol, grid, visited, delrow, delcol, count);
            }
        }
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,  vector<int>(m, 0));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 1;
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(i, j, grid, visited, delrow, delcol, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};
