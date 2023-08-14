 bool toposort(int node, vector<bool>&visited,vector<bool>&dfsVisited,stack<int>&st,  vector<vector<int>>&adj){
     visited[node]=true;
     dfsVisited[node]=true;

     for(auto neighbour:adj[node]){
         if(!visited[neighbour]) {
            if(toposort(neighbour,visited,dfsVisited,st,adj)) return true;
          }
         else if(dfsVisited[neighbour]) return true;
     }
     st.push(node);
     dfsVisited[node]=false;
     return false;
 }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
    //MAKING ADJACENT LIST
        vector<vector<int>>adj(n);
             for(auto &x:prerequisites){
            int a=x[0];
            int b=x[1];
            //{a,b}
            //b-->a
            adj[b].push_back(a);
      }
    //Call dfs Topological sort until function for all componenets
    vector<bool>visited(n,false),dfsVisited(n,false);
    stack<int>st;
     for(int i=0;i<n;i++){
         if(!visited[i]) {
         if(toposort(i,visited,dfsVisited,st,adj)) return {}; //cycle detection hai
         }
     }

      vector<int>ans;
      while(!st.empty()){
       ans.push_back(st.top());
        st.pop();
      }
        return ans;
    }
