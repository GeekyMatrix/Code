class Solution {
public:
int m,n;
  vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}}; 

  bool isSafe(int x,int y){
         if(x>=0 && x<m && y>=0 && y<n) return true;
         return false;
  }
typedef pair<int,pair<int,int>>p; // distance,(x,y);
    int minimumEffortPath(vector<vector<int>>& heights) {
          m=heights.size();
         n=heights[0].size();

         vector<vector<int>>result(m,vector<int>(n,INT_MAX));
         priority_queue<p,vector<p>,greater<p>>pq;
         
         pq.push({0,{0,0}});
         result[0][0]=0;

       while(!pq.empty()){
       int diff=pq.top().first;
       pair<int,int>node=pq.top().second;
       pq.pop();

       int x=node.first;
       int y=node.second;

       if(x==m-1 && y==n-1) return diff;
       
      for(auto dir:directions){
       int x_ =x+dir[0];
        int y_ =y+dir[1];

   
     if(isSafe(x_,y_)){
        int absDiff=abs(heights[x][y]-heights[x_][y_]);
        int maxDiff=max(diff,absDiff);

        if(maxDiff<result[x_][y_]){
              result[x_][y_]=maxDiff;
              pq.push({maxDiff,{x_,y_}});
        }
     }
 }
}     
      return result[m-1][n-1];
    }
};
