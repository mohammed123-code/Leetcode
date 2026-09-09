class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        if(n==1){
            return {0};
        }
        vector<int>indegree(n, 0);
        //making the adjacency list
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }


        //indegree
        // vector<int>indegree(n, 0);
        // for(int i=0;i<n;i++){
        //     for(auto it : adj[i]){
        //         indegree[it]++;
        //     }
        // }

        //GO to the queue if you have the indegree 1, i.e., leaf nodes
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }


        while(n>2){
            int size=q.size();
            n-=size;  //we are going to remove the leafs, so reducing tree's node size
            while(size--){
                int node=q.front();
                q.pop();
                for(auto it : adj[node]){
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                    }
                }
            }
        }




        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;

    }
};