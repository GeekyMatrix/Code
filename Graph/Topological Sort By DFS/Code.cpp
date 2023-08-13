void toposort(int node,vector<bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
  visited[node]=1;

  for(auto neighbour:adj[node]){
  if(!visited[neighbour]) toposort(neighbour,visited,s,adj);
  }
   s.push(node);
}
//Code 
vector<int>topologicalSort(vector<vector<int>>&edges,int v,int e){

  //CREATE ADJACENCY LIST
  unordered_map<int,list<int>>adj;

  for(int i=0;i<e;i++){
  int u=edges[i][0];
  int v=edges[i][1];
  adj[u].push_back(v);
  }

  //CALL DFS TOPOLOGICAL SORT UNTIL FUNCTION FOR ALL COMPONENTS
 vector<bool>visited(v);
  stack<int>s;

  for(int i=0;i<v;i++){
   if(!visited[i]) toposort(i,visited,s,adj);
  }
  //ANSWER MAI PUSH KARDO
  vector<int>ans;
  while(!s.empty()){
 ans.push(s.top());
    s.pop();
  return ans;
  }
}
