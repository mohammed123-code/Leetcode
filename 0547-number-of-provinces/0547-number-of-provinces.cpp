class Solution {
public:

    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis){

        vis[node]=1;

        for(auto it:adjList[node]){

            if(!vis[it]){

                dfs(it,adjList,vis);

            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int v=isConnected.size();


        //given the graph in the adjacency matrix format,
        //i will convert this into adjacency list and then apply the dfs traversal..
        //we can also use bfs

        vector<vector<int>> adjList(v);

        for(int i=0;i<v;i++){

            for(int j=0;j<v;j++){

                if(isConnected[i][j]==1 && i!=j){

                    adjList[i].push_back(j);
                    adjList[j].push_back(i);

                }
            }
        }


        vector<int> vis(v,0);

        int count=0;

        for(int i=0;i<v;i++){

            if(!vis[i]){

                count++;

                dfs(i,adjList,vis);

            }
        }

        return count;
    }
};