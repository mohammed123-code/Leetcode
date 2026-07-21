class Solution {
public:

    void func(vector<vector<char>>& grid, int r, int c){
        int n=grid.size();
        int m=grid[0].size();

        //base case
        if(r<0 || c<0 || r>=n || c>=m){
            return;
        }
        if(grid[r][c]=='0'){
            return;
        }

        grid[r][c]='0';

        func(grid,r-1,c);
        func(grid,r+1,c);
        func(grid,r, c-1);
        func(grid,r, c+1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    func(grid,i,j);
                }
            }
        }

        return count;
    }
};