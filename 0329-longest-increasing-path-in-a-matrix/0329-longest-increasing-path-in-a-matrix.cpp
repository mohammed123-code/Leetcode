class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>indegree(m, vector<int>(n,0));

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    int ni=i+dr[k];
                    int nj=j+dc[k];

                    if(ni>=0 && nj>=0 && ni<m && nj<n && matrix[i][j]<matrix[ni][nj]){
                        indegree[ni][nj]++;
                    }
                }
            }
        }


        queue<pair<int, int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(indegree[i][j]==0){
                    q.push({i,j});
                }
            }
        }


        int res=0;
        while(!q.empty()){
            int size=q.size();
            res++;

            while(size--){
                auto [i, j] =q.front();
                q.pop();


                for(int k=0;k<4;k++){
                    int ni=i+dr[k];
                    int nj=j+dc[k];

                    if(ni>=0 && nj>=0 && ni<m && nj<n && matrix[i][j]<matrix[ni][nj]){
                        indegree[ni][nj]--;
                        if(indegree[ni][nj]==0){
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }
        return res;
    }
};