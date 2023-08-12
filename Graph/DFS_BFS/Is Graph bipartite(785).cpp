class Solution {
public:
//DFS METHOD
 bool dfs(int i,int col,vector<int>&color,vector<vector<int>>& graph){
     color[i]=col;
  //Neighbour pr call karo
     for(auto it:graph[i]){
         if(color[it]==color[i]) return false;

         //Visited nhi hai (never coloured)
         if(color[it]==-1){
             if(dfs(it,!col,color,graph)==false) return false;
         }
     }
     return true;
 }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1); //no node color in the start
        // red=1
        //green =0
        for(int i=0;i<n;i++){
            if(color[i]==-1) {
                if(dfs(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }

//BFS METHOD
bool bfs(int start, vector<int>&color,vector<vector<int>>& graph){
 queue<int>q;
 q.push(start);
  int n=graph.size();
  color[0]=0;

  while(!q.empty()){
  int node=q.front();
  q.pop();

  for(auto it:graph[node]){
  //if the adjacent node having the same color
  //someone did color it on some other path
   if(color[it]==color[node]) return false;

  //if the adjacent node is not yet color 
  // you will give the opposite color of the node
  if(color[it]==-1){
      color[it]=!color[node];
      q.push(it);
  }

  }
  }
 return true;
}
bool isBipartite(vector<vector<int>>& graph) {
   int n=graph.size();
       vector<int>color(n,-1); //no node color in the start
        red=1
        green =0
        for(int i=0;i<n;i++){
            if(color[i]==-1) {
                if(bfs(i,color,graph)==false) return false;
            }
        }
        return true;
}
};
