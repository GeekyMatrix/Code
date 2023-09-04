class Solution {
public:
 bool dfs(int i,int j,int count,vector<vector<char>>& board, string word){

//BASE CASE
 if(count == word.size()) return true;
 //OUT OF BOUNDARY
 if(i==-1 || i==board.size() || j==-1 || j == board[0].size() || board[i][j] !=word[count]) return false;

//DO 
  char temp =board[i][j];
  board[i][j]='*';

//EXPLORE 
bool found=dfs(i+1,j,count+1,board,word) || dfs(i-1,j,count+1,board,word) || dfs(i,j+1,count+1,board,word) ||dfs(i,j-1,count+1,board,word);

 //UNDO 
 board[i][j]=temp;
 return found;
 }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && dfs(i,j,0,board,word)) return true;
            }
        }
        return false;
    }
};
