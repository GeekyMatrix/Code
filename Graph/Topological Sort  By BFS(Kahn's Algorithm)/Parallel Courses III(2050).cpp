class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n , 0);

        //1. Making ADJACENCY LIST
        for(int i = 0; i < relations.size(); i++){
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            adj[u].push_back(v);

            indegree[v]++;
        }
        
        //2.Fill queue those have indegree zero
        queue<int>q;
        vector<int>maxTime(n, 0); //maxTime[i] = maximum time taken by ith course to complete

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) {
            q.push(i);
            maxTime[i] = time[i];
            }
        }

        //3. Simple Bfs
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(int &neighbour : adj[front]){

                maxTime[neighbour] = max(maxTime[neighbour] , maxTime[front] + time[neighbour]); //time update krdo
               indegree[neighbour]--;

               if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        return *max_element(maxTime.begin(),maxTime.end());
    }
};
