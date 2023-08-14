vector<int>shortestpath(vector<pair<int,int>>edges,int n,int m,int s,int t){

//1.CREATE ADJACENCY LIST
  unordered_map<int,list<int,int>>adj;
  for(int i=0;i<edges.size();i++){
 int u=edges[i].first;
 int v=edges[i].second;
  adj[u].push_back(v);
  adj[v].push_back(u);
  }
  
//2.Do Bfs

unordered_map<int,bool>visited;
unordered_map<int,int>parent;
queue<int>q;
  q.push(s);
  parent[s]=-1;
  visited[s]=true;

  while(!q.empty()){
  int front=q.front()
  q.pop();

    for(int i:adj[front]){
       if(!visited) {
            visited[i]=true;
             parent[i]=front;
             q.push(i);
       }
    }
  }
  //3.prepare shortest path
  vector<int>ans;
  int currNode=t;
   ans.push_back(t);

  while(currNode!=s){
   currNode=parent[currNode];
    ans.push_back(currNode);
  }
reverse(ans.begin(),ans.end());
  return ans;
}
