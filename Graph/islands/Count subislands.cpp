class Solution {
public:
 void DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j,int &flag) {
        // boundary checking
   if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size()||grid2[i][j] == 0) return;
             
         if(grid2[i][j]==1){
             if(grid1[i][j]==0){
                 flag=0;
                 return;
             }
         }
        // mark the current as visited
        grid2[i][j] = 0;
        // do DFS in all 4 directions
        DFS(grid1,grid2 ,i+1, j,flag);
        DFS(grid1,grid2 ,i, j-1,flag);
        DFS(grid1,grid2 ,i-1, j,flag);
        DFS(grid1,grid2 ,i, j+1,flag);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                int flag=1;

                if(grid2[i][j]==1){
                    DFS(grid1,grid2,i,j,flag);
                    if(flag==1) count++;
                }
            }
        }
        return count;
    }
};
