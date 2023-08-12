class Solution {
public:
//DFS
  int count=0;
  void dfs(int node,int parent, vector<vector<pair<int,int>>>&adj){
  
    for(auto &p:adj[node]){
      int v=p.first;
      int check=p.second;  //1==asli,0==nakli
     if(v!=parent) {
         if(check==1) count++;
         dfs(v,node,adj);
     }
  }
  }
    int minReorder(int n, vector<vector<int>>& connections) {
     vector<vector<pair<int,int>>>adj(n);
     //ADJACENY LIST
        for(auto it: connections){
             adj[it[0]].push_back({it[1],1});//ASLI
             adj[it[1]].push_back({it[0],0});//NAKLI
        }
       dfs(0,-1,adj);
       return count;
    }

//BFS
int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: connections){
             adj[it[0]].push_back({it[1],1}); //ASLI
             adj[it[1]].push_back({it[0],0}); //NAKLI
        }

        queue<pair<int,int>>q;
        vector<int>vis(n,-1);
        q.push({0,0});
        int ans=0;

        while(!q.empty()){
            int node=q.front().first;
            int wt=q.front().second;
            q.pop();
            vis[node]=1;
           
            ans+=wt;

            for(auto it: adj[node]){
                if(vis[it.first]==-1) q.push(it);
                else continue;
            }
        }
        return ans;
    }

};
