 bool dfsRec(int node,vector<bool>&visited,vector<bool>&dfsvisited,vector<vector<int>>&graph,vector<bool>&present_cycle){
      visited[node]=true;
      dfsvisited[node]=true;
      for(auto neighbour:graph[node]){ 
          if(!visited[neighbour]){
              if(dfsRec(neighbour,visited,dfsvisited,graph,present_cycle)) { 
                     return present_cycle[node]=true; 
                  }
          }
        else if(visited[neighbour]&&dfsvisited[neighbour]) return present_cycle[node]=true;
      }
          dfsvisited[node]=false;
          return false;
  }
  //CODE
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<bool>visited(n,false),dfsvisited(n,false);
      vector<bool>present_cycle(n,false);
        for(int i=0;i<n;i++){ 
            if(!visited[i]){
                dfsRec(i,visited,dfsvisited,graph,present_cycle);
            }
        }
        for(int i=0;i<n;i++){
            if(!present_cycle[i]) ans.push_back(i);
        }
        return ans;
    }
