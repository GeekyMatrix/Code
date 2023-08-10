class Solution {
public:
void dfs(vector<vector<int>>&grid,int i,int j,int &count){
if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0) return;

//MARKS THE CURRENT AS VISITED
grid[i][j]=0;
//INCREASE THE AREA OF THE ISLAND
count++;
//CALL FOR THE OTHERS 4 DIRECTIONALLY
dfs(grid,i+1,j,count);
dfs(grid,i,j-1,count);
dfs(grid,i-1,j,count);
dfs(grid,i,j+1,count);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int ans=0;
     for(int i=0;i<grid.size();i++){
         for(int j=0;j<grid[0].size();j++){
             if(grid[i][j]==1){
                 int count=0;
                 dfs(grid,i,j,count);
                ans=max(ans,count);
             }
         }
     }
         return ans;
    }
};
