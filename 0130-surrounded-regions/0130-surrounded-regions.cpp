class Solution {
public:


    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& visited){
        int row=board.size();
        int col=board[0].size();

        visited[r][c]=1;

        int ri[]={-1, 0, 1, 0};
        int ci[]={0, 1, 0, -1};


        for(int i=0;i<4;i++){
            int nr=r+ri[i];
            int nc=c+ci[i];

            if(nr>=0 && nr<row && nc>=0 && nc<col && (!visited[nr][nc]) && board[nr][nc]=='O'){
                dfs(nr,nc,board,visited);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int row=board.size();
        int col=board[0].size();

        vector<vector<int>>visited(row, vector<int>(col,0));
        


        //top
        for(int i=0;i<col;i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(0,i,board,visited);
            }
        }

        //down
        for(int i=0;i<col;i++){
            if(!visited[row-1][i] && board[row-1][i]=='O'){
                dfs(row-1,i,board,visited);
            }
        }

        //left
        for(int i=0;i<row;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,board,visited);
            }
        }

        //right
        for(int i=0;i<row;i++){
            if(!visited[i][col-1] && board[i][col-1]=='O'){
                dfs(i,col-1,board,visited);
            }
        }

        //final
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};