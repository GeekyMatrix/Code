class Solution {
public:
 int count(vector<vector<int>>& board,int ans){
     int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1) ans++;

            }
        }
      return ans;
 }
bool isvalid(int i,int j,int n,int m,vector<vector<int>>& board){
     if(i>=0&&i<n&&j>=0&&j<m&&board[i][j]==1) return true;
     return false;
 }


  void dfs(vector<vector<int>>& board,int i,int j,int n,int m){
  board[i][j]=0;

   if(isvalid(i+1,j,n,m,board)){
       dfs(board,i+1,j,n,m);
   }
    if(isvalid(i-1,j,n,m,board)){
       dfs(board,i-1,j,n,m);
   }
    if(isvalid(i,j+1,n,m,board)){
       dfs(board,i,j+1,n,m);
   }
    if(isvalid(i,j-1,n,m,board)){
       dfs(board,i,j-1,n,m);
   }
  }



    int numEnclaves(vector<vector<int>>& board) {
         int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            //Left ->top bottom
            int j=0;
            if(board[i][j]==1){
                dfs(board,i,j,n,m);
            }
            //right ->top bottom
             j=m-1;
            if(board[i][j]==1){
                dfs(board,i,j,n,m);
            }
        }
        for(int j=0;j<m;j++){
           //top->left right
            int i=0;
            if(board[i][j]==1){
                dfs(board,i,j,n,m);
            }
            //bottom ->left right
             i=n-1;
            if(board[i][j]==1){
                dfs(board,i,j,n,m);
            }
        }
        return count(board,0);
    }
};
