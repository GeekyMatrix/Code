class Solution {
public:
 //COUNT OF CLOSED ISLAND DFS
  void DFS(vector<vector<int>>& board, int i, int j) {
        // boundary checking|| return if current position is of water or is already visited
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()||board[i][j] == 1)
            return;
             
        // mark the current as visited
       board[i][j] = 1;
        
        // do DFS in all 4 directions
        DFS(board, i+1, j);
        DFS(board, i, j-1);
        DFS(board, i-1, j);
        DFS(board, i, j+1);
    }

  int count(vector<vector<int>>& board){
    int Closed_Islands = 0;
        // We make each 1 as 2 in when it is visited
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                // do DFS in case has not been visited and there is land
                if(board[i][j] == 0) {
                    Closed_Islands++;
                    DFS(board, i, j);
                } 
            }
        }
        return Closed_Islands;
  }


  bool isvalid(int i,int j,int n,int m,vector<vector<int>>& board){
     if(i>=0&&i<n&&j>=0&&j<m&&board[i][j]==0) return true;
     return false;
 }
   //BOUNDARY DFS
   void dfs(vector<vector<int>>& board,int i,int j,int n,int m){
  board[i][j]=1;

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

    int closedIsland(vector<vector<int>>& board) {
         int n=board.size();
        int m=board[0].size();

       //MARK THE BOUNDARY

        for(int i=0;i<n;i++){
            //Left ->top bottom
            int j=0;
            if(board[i][j]==0){
                dfs(board,i,j,n,m);
            }
            //right ->top bottom
             j=m-1;
            if(board[i][j]==0){
                dfs(board,i,j,n,m);
            }
        }
        for(int j=0;j<m;j++){
           //top->left right
            int i=0;
            if(board[i][j]==0){
                dfs(board,i,j,n,m);
            }
            //bottom ->left right
             i=n-1;
            if(board[i][j]==0){
                dfs(board,i,j,n,m);
            }
        }
        return count(board);
    }
};
