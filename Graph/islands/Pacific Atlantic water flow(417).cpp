class Solution {
public:
void dfs(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<int>>&visited){
    //Boundary condition
 if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || visited[i][j]==1 ||heights[i][j]<prev) 
    return;
    
    //Visited mark karo
    visited[i][j]=1;

    dfs(heights,i+1,j,heights[i][j],visited);
    dfs(heights,i-1,j,heights[i][j],visited);
    dfs(heights,i,j+1,heights[i][j],visited);
    dfs(heights,i,j-1,heights[i][j],visited);
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
       vector<vector<int>> ans;
        if(heights.size()<1) return ans;

       vector<vector<int>>pacific(n,vector<int>(m,0)); 
        vector<vector<int>>atlantic(n,vector<int>(m,0));
      
        for(int i=0;i<n;i++){
             //Left ->top bottom
             int j=0;
            dfs(heights,i,j,INT_MIN,pacific);
              //right ->top bottom
             j=m-1;
            dfs(heights,i,j,INT_MIN,atlantic);
        }
        
        for(int j=0;j<m;j++){
            //top->left right
            int i=0;
            dfs(heights,i,j,INT_MIN,pacific);
            //bottom ->left right
             i=n-1;
            dfs(heights,i,j,INT_MIN,atlantic);
        }

       //Storing the answer
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(pacific[i][j]==1 && atlantic[i][j]==1){
                      ans.push_back({i,j});
                  }
              }
          }
       return ans;
    } 
};
