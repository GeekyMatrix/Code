class Solution {
public:
//Recursive Method
 int solve(int index,int endIndex,vector<int>& slices,int n){
     //BASE CASE
     if(n==0 || index>endIndex) return 0;

     int Take=slices[index]+solve(index+2,endIndex,slices,n-1);
     int nonTake=0+solve(index+1,endIndex,slices,n);
     return max(Take,nonTake);
 }

    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();

        int case1=solve(0,k-2,slices,k/3);
        int case2=solve(1,k-1,slices,k/3);
        return max(case1,case2);
    }

//Memoization Method
 int solve(int index,int endIndex,vector<int>& slices,int n, vector<vector<int>>&t){
     //BASE CASE
     if(n==0 || index>endIndex) return 0;
    
    if(t[index][n]!=-1) return t[index][n];

     int Take=slices[index]+solve(index+2,endIndex,slices,n-1,t);
     int nonTake=0+solve(index+1,endIndex,slices,n,t);
     return t[index][n]=max(Take,nonTake);
 }

    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
       vector<vector<int>>t1(k,vector<int>(k,-1));
        int case1=solve(0,k-2,slices,k/3,t1);

       vector<vector<int>>t2(k,vector<int>(k,-1));
        int case2=solve(1,k-1,slices,k/3,t2);
        return max(case1,case2);
    }

//Dp method
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
       vector<vector<int>>dp1(k+2,vector<int>(k+2,0));

       vector<vector<int>>dp2(k+2,vector<int>(k+2,0));
        
        for(int index=k-2;index>=0;index--){
            for(int n=1;n<=k/3;n++){
 
      int Take=slices[index]+dp1[index+2][n-1];
     int nonTake=0+dp1[index+1][n];
     dp1[index][n]=max(Take,nonTake);
            }
        }
        int case1=dp1[0][k/3];

         for(int index=k-1;index>=1;index--){
            for(int n=1;n<=k/3;n++){
 
      int Take=slices[index]+dp2[index+2][n-1];
     int nonTake=0+dp2[index+1][n];
     dp2[index][n]=max(Take,nonTake);
            }
        }
        int case2=dp2[1][k/3];

        return max(case1,case2);
    }

//DP with space optimisation
 int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();

         vector<int> prev1(k+2,0);  //index
         vector<int>curr1(k+2,0); //index+1
         vector<int> next1(k+2,0); //index+2

         vector<int> prev2(k+2,0);  //index
         vector<int> curr2(k+2,0); //index+1
         vector<int>next2(k+2,0); //index+2

        for(int index=k-2;index>=0;index--){
            for(int n=1;n<=k/3;n++){
 
      int Take=slices[index]+next1[n-1];
     int nonTake=0+curr1[n];
     prev1[n]=max(Take,nonTake);
            }
        next1=curr1;
        curr1=prev1;

        }
        int case1=curr1[k/3];

         for(int index=k-1;index>=1;index--){
            for(int n=1;n<=k/3;n++){
    int Take=slices[index]+next2[n-1];
     int nonTake=0+curr2[n];
     prev2[n]=max(Take,nonTake);
            }
        next2=curr2;
        curr2=prev2;
        }
        int case2=curr2[k/3];

        return max(case1,case2);
    }
};
