class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(n);
        // for(int i=0;i<n;i++){
        //     for(auto it : richer[i]){
        //         adj.push_back(it);
        //     }
        // }

        vector<int>indegree(n,0);


        for(auto it : richer){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }


        while(!q.empty()){
            int node=q.front();   //'node' is the RICH PEARSON
            q.pop();

            for(auto it : adj[node]){  //'it' is the POOR PEARSON  (node->it) node is richer that it
                if(quiet[ans[node]]<quiet[ans[it]]){
                    ans[it]=ans[node];
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return ans;
    }
};