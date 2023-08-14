vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     int n=numCourses;
  //MAKING ADJACENT LIST
        vector<vector<int>>adj(n);
        vector<int>indegree(n);

        for(auto &x:prerequisites){
            int a=x[0];
            int b=x[1];
            //{a,b}
            //b-->a
            adj[b].push_back(a);
  //Find all indegree
            indegree[a]++;
        }
  //0 indegrees walo ko push kardo
  queue<int>q;
  for(int i=0;i<n;i++) {
      if(indegree[i]==0) q.push(i);
  }
  //Do Bfs
  vector<int>ans;
  int count=0;
  while(!q.empty()){
      int front=q.front();
      q.pop();
  //ans store kardo
  ans.push_back(front);
  count++;
  //neighbour indegree update
  for(auto neighbour:adj[front]){
      indegree[neighbour]--;
      if(indegree[neighbour]==0) q.push(neighbour);
  }
  }
  if(count==n) return ans;
  else return {};
 }
