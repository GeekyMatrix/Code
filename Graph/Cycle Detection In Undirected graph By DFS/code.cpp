// if(visited hai & !parent hai) then cycle detection hai

bool isCycleDFS(int node,int parent, unordered_map<int,bool>&visited,unordered_map<int,list<int>>adj){
 visited[node]=true;

  for(auto neighbour:adj[node]){
  if(!visited[neighbour]){
  bool cycleDetected=isCycleDFS(neighbour,node,visited,adj);
    if(cycleDetected) return true;
  }
    else if(neighbour!=parent)  return true; // cycle present 
  }
  }
 return false;
}

//Code ------->>>>>>>>>>>>>
string cycleDetection(vector<vector<int>>edges,int n,int m){
//Create Adjacency list
  unordered_map<int,list<int>>adj;
  for(int i=0;i<m;i++){
  int u=edges[i][0];
  int v=edges[i][1];

  adj[u].push_back(v);
  adj[v].push_back(u);
  }
//To handle disconnected components
  unordered_map<int,bool>visited;

  for(int i=0;i<n;i++){
   if(!visited[i]){
   bool ans=isCycleDfs(i,-1,visited,adj);
     if(ans==1) return "YES";
   }
  }
return "No";
}
