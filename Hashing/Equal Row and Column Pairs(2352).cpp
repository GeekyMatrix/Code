class Solution {
public:
//By transpose method
    int equalPairs(vector<vector<int>>& grid) {
        int count_pairs = 0;
        int n = grid.size();
        vector<vector<int>>transpose =  grid;

        for(int i = 0; i < n; i++){ //Trnaspose krdo
            for(int j = i; j < n; j++){
                swap(transpose[i][j],transpose[j][i]);
            }
        }

        for(int i = 0; i < n; i++){ //Check krlo same row wale ko
            for(int j = 0; j < n; j++){
                if(grid[i] == transpose[j]) count_pairs++;
            }
        }
        return count_pairs;
    }

//BRUTE FORCE O(n^3)
int equalPairs(vector<vector<int>>& grid) {
  int n = grid.size();
  int cnt = 0;

  for(int r = 0; r < n; r++){ //Row fixed kr diya
      for(int c = 0; c < n; c++){ //Column fixed kr diya

          bool is_true = true; 
         for(int i = 0; i < n; i++){   // check the each element of row and column
           if(grid[r][i] != grid[i][c]){
               is_true = false;
               break;
           }
         }
         if(is_true == true) cnt++;
      }
  }
   return cnt;
}

//OPTIMAL CODE  0(n^2)
int equalPairs(vector<vector<int>>& grid) {
  int n = grid.size();
  int cnt = 0;
  map<vector<int>,int>m;

 for(int r = 0; r < n; r++) m[grid[r]]++; //Count the freq of each row
  
  for(int c = 0; c < n;c++){ //Iterate on the col wise
   
   vector<int>store;
   for(int row = 0; row < n; row++) store.push_back(grid[row][c]);  //store the col element value
 
   cnt+=m[store]; // cnt if it is present in map
  }
  return cnt;
}
};
