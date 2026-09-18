class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>outdegree(n,0);

        

        

        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
        }
        vector<vector<int>>reverseGraph(n);

        for(int u=0;u<n;u++){
            for(auto v : graph[u]){
                reverseGraph[v].push_back(u);
            }
    }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }

        vector<int>res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto it : reverseGraph[node]){
                outdegree[it]--;
                if(outdegree[it]==0){
                    q.push(it); 
                }
            }

        }
        sort(res.begin(), res.end());
        return res;
    }
};