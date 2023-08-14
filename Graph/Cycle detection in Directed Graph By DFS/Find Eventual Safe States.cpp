 bool dfsRec(int node,vector<bool>&visited,vector<bool>&dfsvisited,vector<vector<int>>&graph){
      visited[node]=true;
      dfsvisited[node]=true;
      for(auto neighbour:graph[node]){ 
          if(!visited[neighbour]){
              if(dfsRec(neighbour,visited,dfsvisited,graph)) { 
                     return true; 
                  }
          }
        else if(visited[neighbour]&&dfsvisited[neighbour]) return true;
      }
          dfsvisited[node]=false;
          return false;
  }
  //CODE
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,false),dfsvisited(n,false);
        for(int i=0;i<n;i++){ 
            if(!visited[i]){
                dfsRec(i,visited,dfsvisited,graph);
            }
        }
        
         vector<int>safenodes;
        for(int i=0;i<n;i++){
            if(dfsvisited[i]==false) safenodes.push_back(i);
        }
        return safenodes;
    }
