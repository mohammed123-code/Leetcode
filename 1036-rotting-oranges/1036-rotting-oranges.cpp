class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;

        //we are going to count the fresh oranges and put the rotten oranges in the queue
        int fresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }





        //no freah ornage means....
        if(fresh==0){
            return 0;
        }

        //result time in MINUTES
        int time=0;

        //directions
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};



        //now BFS starts..............->>>>
        while(!q.empty()){
            int size=q.size();
            
            

            for(int i=0;i<size;i++){
                auto Front=q.front();
                q.pop();

                int r=Front.first;
                int c=Front.second;

                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;

                        //again adding the new rotten in the queue
                        q.push({nr,nc});
                    }


                }
            }

            if(!q.empty()){
                time++;
            }
        }

        if(fresh==0){
            return time;
        }
        return -1;
    }
};