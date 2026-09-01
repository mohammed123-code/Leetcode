class Solution {
public:
    // Standard DFS function to explore and mark connected 'O's
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& visited) {
        int row = board.size();
        int col = board[0].size();
        
        // Mark current cell as visited
        visited[r][c] = 1;
        
        // 4 Directional arrays: Up, Right, Down, Left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            
            // Check boundary conditions, unvisited status, and if it's an 'O'
            if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col 
                && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int row = board.size();          
        int col = board[0].size();       
        vector<vector<int>> visited(row, vector<int>(col, 0));

        // top boundary -> Trigger DFS if 'O' found
        for(int i = 0; i < col; i++){
            if(!visited[0][i] && board[0][i] == 'O'){
                dfs(0, i, board, visited);
            }
        }

        // bottom boundary -> Trigger DFS if 'O' found
        for(int i = 0; i < col; i++){
            if(!visited[row - 1][i] && board[row - 1][i] == 'O'){
                dfs(row - 1, i, board, visited);
            }
        }

        // left boundary -> Trigger DFS if 'O' found
        for(int i = 0; i < row; i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, visited);
            }
        }

        // right boundary -> Trigger DFS if 'O' found
        for(int i = 0; i < row; i++){
            if(!visited[i][col - 1] && board[i][col - 1] == 'O'){
                dfs(i, col - 1, board, visited);
            }
        }

        // Final Step: Flip captured regions
        // If an 'O' is not visited, it is not connected to a boundary -> Flip to 'X'
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
