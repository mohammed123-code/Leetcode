class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n=graph.size();

        // 0-> DRAW
        // 1-> MOUSE wins
        // 2-> CAT wins


        vector<vector<vector<int>>>result(n,vector<vector<int>>(n,vector<int>(2,0)));

        //degree[mouse][cat][turn] ---> number of possible moves from the state
        vector<vector<vector<int>>>degree(n, vector<vector<int>>(n, vector<int>(2,0)));

        //now we are going to calculate the degree (no of possiblr moves)
        //remember mouse starts first
        for(int mouse=0;mouse<n;mouse++){
            for(int cat=0;cat<n;cat++){
                
                //---MOUSE can move to all neighbours
                degree[mouse][cat][0]=graph[mouse].size();

                //---CAT cannot move to node 0
                for(int node : graph[cat]){
                    if(node!=0){
                        degree[mouse][cat][1]++;
                    }
                }
            }
        }


        //pushing all the WINNING states to the queueu
        queue<tuple<int, int, int>>q;

        //..1..Mouse wins -> when it reachs 0
        for(int cat =0;cat<n;cat++){
            result[0][cat][0]=1;    //mouse | cat | turn
            result[0][cat][1]=1;

            q.push({0,cat,0});
            q.push({0,cat,1});
        }

        //..2..Cat wins -> when cat reaches mouse (cat and mouse in same place)
        for(int i=1;i<n;i++){
            result[i][i][0]=2;
            result[i][i][1]=2;

            q.push({i,i,0});
            q.push({i,i,1});
        }


        while(!q.empty()){
            auto [mouse,cat,turn]=q.front();
            q.pop();
            int curr=result[mouse][cat][turn];

            //mouse turn
            if(turn ==0){
                // If it is Mouse's turn now,
                // Cat moved immediately before this.
                //---------------------------------------------
                // So we need to find :-
                // Where could Cat have been before?
                for(int preCat : graph[cat]){
                    if(preCat==0) continue; //cat not allowed in node 0
                    
                    int preMouse=mouse; //mouse doent move
                    int preTurn=1; // previous was the cat turn

                    //already visted state
                    if(result[preMouse][preCat][preTurn]!=0) continue;


                    //CAT WINNING State
                    if(curr==2){
                        result[preMouse][preCat][preTurn]=2;
                        q.push({preMouse, preCat, preTurn});
                    }
                    //CAT NOT WINNING State
                    else{
                        degree[preMouse][preCat][preTurn]--;
                        if(degree[preMouse][preCat][preTurn]==0){
                            result[preMouse][preCat][preTurn]=1;
                            q.push({preMouse, preCat, preTurn});
                        }
                    }
                }
            }

            //cat turn
            else{
                // If it is Cat's turn now,
                // Mouse moved immediately before this.
                //-------------------------------------------
                // So we need to find:
                // Where could Mouse have been before?
                for(int preMouse : graph[mouse]){
                    int preCat=cat;
                    int preTurn=0;

                    if(result[preMouse][preCat][preTurn]!=0) continue;

                    //mousen winning state
                    if(curr==1){
                        result[preMouse][preCat][preTurn]=1;
                        q.push({preMouse, preCat, preTurn});
                    }
                    //mouse not winning state
                    else{
                        degree[preMouse][preCat][preTurn]--;
                        if(degree[preMouse][preCat][preTurn]==0){
                            result[preMouse][preCat][preTurn] = 2;

                            q.push({preMouse,preCat,preTurn});
                        }
                    }
                }
            }
        }


        
        return result[1][2][0];

    }
};