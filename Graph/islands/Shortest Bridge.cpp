class Solution {
public:
  void DFS(vector<vector<int>>& grid, int i, int j, vector<pair<int,int>>&r) {
        // boundary checking|| return if current position is of water or is already visited
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()||grid[i][j] == 0)
            return;
             
        // mark the current as visited
        grid[i][j] = 0;
        r.push_back(make_pair(i,j));
        // do DFS in all 4 directions
        DFS(grid, i+1, j,r);
        DFS(grid, i, j-1,r);
        DFS(grid, i-1, j,r);
        DFS(grid, i, j+1,r);
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
          int islands = 0;
         // We make each 1 as 2 in when it is visited
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                // do DFS in case has not been visited and there is land
                if(grid[i][j] == 1) {
                     islands++;
                   if(islands==1) DFS(grid, i, j,x);
                  else if(islands==2) DFS(grid, i, j,y);
                } 
            }
        }
        //FIND THE MINIMUM DISTANCE
          int min_dist=INT_MAX;
          for(int i=0;i<x.size();i++){
              for(int j=0;j<y.size();j++){
                  int dist=abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second)-1;
                  if(dist<min_dist) min_dist=dist;
              }
          }
        return min_dist;
    }
};
