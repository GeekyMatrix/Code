class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //red->0 blue->1
        vector<vector<pair<int,int>>>adj(n);
        //RED edges ko insert krdo
        for(auto &it:redEdges)  adj[it[0]].push_back({it[1],0});
        //BLUE edges ko insert krdo
         for(auto &it:blueEdges)  adj[it[0]].push_back({it[1],1});

         vector<int>ans(n,-1);
         vector<vector<bool>>visited(n,vector<bool>(2));
         queue<vector<int>>q;

         q.push({0,0,-1}); //node, steps, color
         visited[0][0]=true;
         visited[0][1]=true;
         ans[0]=0;

         while(!q.empty()){
             vector<int>curr=q.front();
             q.pop();
             int node=curr[0] ,steps=curr[1],prevColor=curr[2];

            for(auto &[neighbour,color]:adj[node]){
                if(!visited[neighbour][color] && color!=prevColor){
                    visited[neighbour][color]=true;
                    q.push({neighbour,1+steps,color});
                    if(ans[neighbour]==-1) ans[neighbour]=1+steps;
                }
            }
         }
         return ans;
    }
};
