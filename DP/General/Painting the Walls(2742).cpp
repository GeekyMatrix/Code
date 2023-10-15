class Solution {
public:
//Recursion
int n;
int solve(int idx , vector<int>& cost, vector<int>& time , int remaining){
   //BASE CASE
    if(remaining <= 0) return 0; //NO COST
    
    if(idx >= n) return 1e9; //INVALID CASE

   //EXPLORE
   int paint_idx =  cost[idx] + solve(idx + 1  , cost , time , remaining - 1 - time[idx]);

   int Not_paint_idx =   solve(idx + 1 , cost , time , remaining);

   return min(paint_idx , Not_paint_idx);
}
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        return solve(0 , cost , time , n);
    }

//MEMOIZATION
int t[501][501];
int n;
int solve(int idx , vector<int>& cost, vector<int>& time , int remaining){
   //BASE CASE
    if(remaining <= 0) return 0; //NO COST
    
    if(idx >= n) return 1e9; //INVALID CASE
   
    if(t[idx][remaining]!=-1) return t[idx][remaining];
   //EXPLORE
   int paint_idx =  cost[idx] + solve(idx + 1  , cost , time , remaining - 1 - time[idx]);

   int Not_paint_idx =   solve(idx + 1 , cost , time , remaining);

   return t[idx][remaining] = min(paint_idx , Not_paint_idx);
}
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memset(t , -1 ,sizeof(t));
        return solve(0 , cost , time , n);
    }
};
