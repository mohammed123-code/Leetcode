class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    int dfs(vector<vector<int>>& matrix, int m , int n, int i, int j, vector<vector<int>>&memo){
        if(memo[i][j]!=-1){   //if i ahve already the value, just take it, dont do again
            return memo[i][j];
        }
        int maxi=0;
        for(int k=0;k<4;k++){
            int ni=i+dr[k];
            int nj=j+dc[k];
            if(ni>=0 && nj>=0 && ni<m && nj<n && matrix[i][j]<matrix[ni][nj]){
                int len=dfs(matrix, m, n, ni, nj, memo);
                maxi=max(maxi, len);
            }
        }
        memo[i][j]=maxi+1;
        return maxi+1;  //add one for current pos
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //lets try using DFS and memo as we got 
        // TIME LIMIT EXCEEDED so lets add memo table
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>memo(m ,vector<int>(n, -1));  //---->this is the memo table


        int maxipath=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int path=dfs(matrix, m, n, i, j, memo);
                maxipath=max(maxipath, path);
            }
        }
        return maxipath;
    }
};