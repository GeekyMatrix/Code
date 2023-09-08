void dfs(int node, unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj, vector<int>&component){
 component.push_back(node);
 visited[node]=true;

  //haar connected node ke liye recursive call marro
  for(auto i:adj[node]){
  if(!visited[i]){
  dfs(i,visited,adj,component);
  }
  }
}

Vector<vector<int>depthfirstSearch(int V,int E,vector<vector,int>&edges){
//Prepare Adj list
  unordered_map<int,list<int>>adj;
  for(int i=0;i<edges.size();i++){
   int u=edges[i][0];
    int v=edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 vector<vector<int>>ans;
  unordered_map<int,bool>visited;

  //For all node call Dfs if not visited 
  for(int i=0;i<V;i++){
 if(!visited[i]){
 vector<int>component;
   dfs(i,visited,adj,component);
   ans.push_back(component);
 }
  }
return ans;
}
