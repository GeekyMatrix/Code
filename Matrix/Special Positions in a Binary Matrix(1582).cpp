class Solution {
public:
// //Approach-1 (Brute Force)
// //T.C : O((m*n) (m+n))
// //S.C : O(1)
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(mat[row][col] == 1){

                    //Check each row 
                    bool good = true;
                    for(int r = 0; r < m; r++){
                        if(r != row && mat[r][col] == 1){
                            good = false;
                            break;
                        }
                    }
                    //Check each col
                    for(int c = 0; c < n; c++){
                        if(c != col && mat[row][c] == 1){
                            good = false;
                            break;
                        }
                    }
                     if(good) cnt++;
                }
            }
        }
        return cnt;
    }

//Approach-2(Storing count of 1s in rows and cols)
//T.C : O(m*n)
//S.C : O(m+n)
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;
        
        vector<int>rowCnt(m,0);
         vector<int>colCnt(n,0);

      //1. count krlo each row & col pr kitne 1 hai
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(mat[row][col] == 1){
                   rowCnt[row]++;
                   colCnt[col]++;
                }
            }
        }
        // jis pr sirf 1 hoga usko consider krlo
            for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(mat[row][col] == 1){
                   if(rowCnt[row] == 1 && colCnt[col] == 1) cnt++;
                }
                }
            }
        return cnt;
    }
};
