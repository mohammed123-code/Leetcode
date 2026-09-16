class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    
    int dfs(int r, int c, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>&memo){
        if(memo[r][c]!=-1){
            return memo[r][c];
        }
        int maxi=0;
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr>=0 && nc>=0 && nr<m && nc<n  ){
                if(matrix[nr][nc]>matrix[r][c]){
                    int len=dfs(nr, nc, m, n, matrix, memo);
                    maxi=max(maxi, len);
                }
            }

        }
        memo[r][c]=maxi+1;
        return maxi+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>memo(m, vector<int>(n,-1));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int len=dfs(i,j,m,n,matrix,memo);
                maxi=max(maxi, len);              
            }
            
        }
        return maxi;
    }
};