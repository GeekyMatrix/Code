class Solution {
public:
int m,n;
  vector<vector<int>>directions{{1,1},{-1,-1},{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1}}; 

  bool isSafe(int x,int y){
         if(x>=0 && x<m && y>=0 && y<n) return true;
         return false;
  }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();

        if(m==0 || n==0 || grid[0][0]!=0) return -1;

        queue<pair<int,int>>que;
        que.push({0,0});
        grid[0][0]=1;

        int level=0;

        while(!que.empty()){
            int N=que.size();

            while(N--){
            auto curr=que.front();
            que.pop();

            int x=curr.first;
            int y=curr.second;
             
             if(x==m-1 && y==n-1) return level+1;

            for(auto dir:directions){
              int x_=x+dir[0];
              int y_=y+dir[1];

              if(isSafe(x_,y_) && grid[x_][y_]==0){
                  que.push({x_,y_});
                  grid[x_][y_]=1;
                  
              }
            }
            }
            level++;
        }
        return -1;
    }
};
