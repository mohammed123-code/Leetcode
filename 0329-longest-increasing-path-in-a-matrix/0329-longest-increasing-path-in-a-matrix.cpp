class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //converting the matrix to a graph
        int m=matrix.size();
        int n=matrix[0].size();
        
        //insted of creating the new graph, we create the indegree matrix for it
        vector<vector<int>>indegree(m, vector<int>(n,0));

        //all four directions
        int dr[4]={-1, 1, 0, 0};
        int dc[4]={0, 0, -1, 1};


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

        // //see the indegree for understanding
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<indegree[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        //Hye if u have the indegree 0, go to the queue
        queue<pair<int, int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(indegree[i][j]==0){
                    q.push({i,j});
                }
            }
        }




        int len=0;  //-->this is the output variable


        //now the   KAHN's Algoo..
        while(!q.empty()){
            int size=q.size();
            len++;

            while(size--){

                
                pair<int,int> node=q.front();
                int i=node.first;
                int j=node.second;

                //or  auto {i, j}= q.front();


                q.pop();


                for(int k=0;k<4;k++){
                    int ni=i+dr[k];
                    int nj=j+dc[k];

                    if(ni>=0 && nj>=0 && ni<m && nj<n && matrix[ni][nj]>matrix[i][j]){
                        indegree[ni][nj]--;
                        if(indegree[ni][nj]==0){
                        q.push({ni, nj});
                    }
                    }
                    
                }
            }
        }
        


        



   return len;



    }
};

