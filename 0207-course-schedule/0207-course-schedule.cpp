class Solution {
public:
    //   |```|   |`````  |``````
    //   |   |   |       |
    //   |---    |````    `````|
    //   |   |   |             |
    //   |___|   |       ______|
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto it : prerequisites){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
        }



        vector<int>indegree(numCourses);
        
        queue<int>q;

        //filling the indegree
        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        //go to the queue when u have the indegree 0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return count==numCourses;
    }
};