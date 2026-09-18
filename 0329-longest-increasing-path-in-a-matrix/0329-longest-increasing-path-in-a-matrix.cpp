class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    int dfs(int i, int j, vector<vector<int>>&matrix, int m, int n, vector<vector<int>>&memo){
        if(memo[i][j]!=0){
            return memo[i][j];
        }
        int maxi=0;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            
            if(nr>=0 && nc>=0 && nr<m && nc<n && matrix[i][j]<matrix[nr][nc]){
                int len=dfs(nr, nc, matrix, m, n, memo);
                maxi=max(len, maxi);
            }
        }
        memo[i][j]=maxi+1;
        return maxi+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>memo(m, vector<int>(n,0));

        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                    int len=dfs(i, j, matrix, m, n, memo);
                    maxi=max(len, maxi);
                
            }
        }
        return maxi;
    }
};