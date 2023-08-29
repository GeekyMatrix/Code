class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> ans;
         int n=matrix.size();
         int m=matrix[0].size();

         int count=1;
         int total=n*m;
         //INDEX INTIALIZATION
         int startingRow=0;
         int startingCol=0;
         int endingRow=n-1;
         int endingCol=m-1;

         while(count<=total){
           //PRINT STARTING ROW
        for(int i=startingCol;count<=total&&i<=endingCol;i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
           //PRINT ENDING COLUMN
         for(int i=startingRow;count<=total&&i<=endingRow;i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;
          //PRINT ENDING ROW
          for(int i=endingCol;count<=total&&i>=startingCol;i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
         endingRow--;
          //PRINT STARTING COLUMN
             for(int i=endingRow;count<=total&&i>=startingRow;i--){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
          startingCol++;
         }
         return ans;
    }
};
