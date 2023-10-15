class Solution {
public:
//Memoization 
int t[501][501];
int M = 1e9 + 7;
int n;
int solve(int idx , int steps){
          //BASE CASE
        if(idx < 0 || idx >= n) return 0;

        if(steps == 0)     return idx == 0;
         
        if(t[idx][steps]!=-1) return t[idx][steps];

        int result = solve(idx + 1 , steps - 1 ) % M; //RIGHT
        result = (result + solve(idx - 1, steps - 1 )) % M; //LEFT
        result = (result + solve(idx , steps - 1 ) )% M;   //STAY

        return t[idx][steps] = result % M;
        
}
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen , steps);
        n = arrLen;
        memset(t , -1 , sizeof(t));
      return solve( 0 , steps);
    }

//Memoization + space optimisation
int t[501][501];
int M = 1e9 + 7;
int n;
int solve(int idx , int steps){
          //BASE CASE
        if(idx < 0 || idx >= n) return 0;

        if(steps == 0)     return idx == 0;
         
        if(t[idx][steps]!=-1) return t[idx][steps];

        int result = solve(idx + 1 , steps - 1 ) % M; //RIGHT
        result = (result + solve(idx - 1, steps - 1 )) % M; //LEFT
        result = (result + solve(idx , steps - 1 ) )% M;   //STAY

        return t[idx][steps] = result % M;
        
}
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen , steps / 2 + 1); // x = steps / 2; -> plus 1 for ceil
        n = arrLen;
        memset(t , -1 , sizeof(t));
      return solve( 0 , steps);
    }
};
