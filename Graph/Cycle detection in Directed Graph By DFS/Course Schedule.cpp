class Solution {
public:
//Cycle detection in directed graph
   bool Dfs(int s, vector<bool>&visited, vector<bool>&currvisited,vector<int>adj[]){
  visited[s]=true;
  currvisited[s]=true;
  for(auto neighbour:adj[s]){
      if(!visited[neighbour]) {
          if(Dfs(neighbour,visited,currvisited,adj)) return true;
      }
      else if(visited[neighbour]&&currvisited[neighbour]) return true;
  }
   currvisited[s]=false;
   return false;
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<bool>Visited(n,false);
        vector<bool>currVisited(n,false);
    //MAKING ADJACENT LIST
       vector<int>adj[n];
        for(auto x:prerequisites){
        vector<int>data=x;
        int a=data[0];
        int b=data[1];
        //b---->a
        adj[b].push_back(a);
        }
    //Dfs call 
    for(int i=0;i<n;i++){
        if(!Visited[i]){
            if(Dfs(i,Visited,currVisited,adj)) return false; //course complete nhi kr skte
    }
    }
    return true; //course complete kr skte ho
    }
};
