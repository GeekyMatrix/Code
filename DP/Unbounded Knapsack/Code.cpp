//Recursive Approach

int Knapsack(int w,int wt[],int val[],int n){
 if(n==0 || w==0)return 0;

if(wt<[n-1]<=w) return max(val[n-1]+knapsack(w-wt[n-1],wt,val,n),knapsack(w,wt,val,n-1);

else if(wt[n-1]>w) return knapsack(w,wt,val,n-1);
}

//MEMOIZATION METHOD
int solve(int wt[],int val[],int w,int n,int t){
if(n==0 || w==0) return 0;

if(t[n][w]!=-1) return t[n][w];

if(wt<[n-1]<=w) return t[n][w]=max(val[n-1]+solve(w-wt[n-1],wt,val,n,t),solve(w,wt,val,n-1,t);

else if(wt[n-1]>w) return t[n][w]=solve(w,wt,val,n-1,t);

}
int Knapsack(int w,int wt[],int val[],int n){
 vector<vector<int>>t(n,vector<int>(w+1,-1));
  return solve(wt,val,w,n,t);
}

//DP METHOD

int knapsack(int w,int wt[],int val[],int n){
 int **t=new int[n+1];
  for(int i=0;i<=n;i++){
 t[i]=new int[w+1];
  }
  //FILL THE IST row and ist col
  for(int i=0;i<n+1;i++){
     for(int j=0;j<w+1;j++){
     if(i==0 || j==0) t[i][j]=0;
     }
     }
//CHOICE DIAGRAM
  for(int i=1;i<n+1;i++){
      for(int j=1;j<w+1;j++){
        if(wt[i-1]<=j){
        t[i[[j]=max(val[i-1]+t[i][j-wt[i-1], t[i-1][j]);
        }
       else t[i][j]=t[i-1][j];
      }
  }
  return t[n][w];
}
